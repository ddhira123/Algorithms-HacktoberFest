using System;

namespace ImprovedPerlinNoise
{
    class PerlinNoise
    {
        // Hash lookup table as defined by Ken Perlin.
        // This is a randomly arranged array of all numbers from 0-255 inclusive.
        private static readonly int[] permutation = { 151,160,137,91,90,15,					  
		131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,	
		190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
        88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
        77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
        102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
        135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
        5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
        223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
        129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
        251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
        49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
        };

        // Doubled permutation to avoid overflow
        private static readonly int[] p;                                                    

        static PerlinNoise()
        {
            p = new int[512];
            for (int x = 0; x < 512; x++)
            {
                p[x] = permutation[x % 256];
            }
        }

        public static double Perlin2DNoise(double x, double y)
        {
            // xi, yi -> between 0 and 255
            int xi = (int)x & 255;                              
            int yi = (int)y & 255;                                                         

            // Coordinate of rectangle
            //    0,0  0,1
            //    1,0  1,1
            // Permutation 2 times for 2d Perlin Noise
            int g1 = p[p[xi] + yi];
            int g2 = p[p[xi + 1] + yi];
            int g3 = p[p[xi] + yi + 1];
            int g4 = p[p[xi + 1] + yi + 1];

            //Get fractional part of x and y e.g. 1.23 -> 0.23
            double xf = x - (int)x;                             
            double yf = y - (int)y;

            // Smoothing the result using fade function 
            double u = Fade(xf);
            double v = Fade(yf);

            // Dot product
            double d1 = Grad(g1, xf, yf);
            double d2 = Grad(g2, xf - 1, yf);
            double d3 = Grad(g3, xf, yf - 1);
            double d4 = Grad(g4, xf - 1, yf - 1);

            //Linear interpolation
            double x1 = Lerp(d1, d2, u);
            double x2 = Lerp(d3, d4, u);
            double yLerp = Lerp(x1, x2, v);

            return yLerp;
        }

        public static double OctavePerlin(double x, double y, int octaves, double persistence)
        {
            // "frequency" period at which data is sampled
            // "amplitude" the range at which the result can be
            // "octave" number of steps, increase for finer result
            // "persistence" value that is multiplied in every step
            // High persistence -> Noisy pattern, Low persistence -> Subtle pattern

            double total = 0;
            double frequency = 1;
            double amplitude = 1;
            double maxValue = 0;

            //frequency = 2*i
            //amplitude = persistence*i

            for (int i = 0; i < octaves; i++)
            {
                total += Perlin2DNoise(x * frequency, y * frequency) * amplitude;

                maxValue += amplitude;
                
                amplitude *= persistence;
                frequency *= 2;
            }

            return total / maxValue;
        }

        public static double Fade(double t)
        {
            // Fade function as defined by Ken Perlin.
            // This eases coordinate values so that they will "ease" towards integral values.
            // This ends up smoothing the final output.
            // 6t^5 - 15t^4 + 10t^3
            return t * t * t * (t * (t * 6 - 15) + 10);         
        }

        public static double Lerp(double x, double y, double by)
        {
            return x * (1 - by) + y * by;
        }

        public static double Grad(int hash, double x, double y)
        {
            // Dot product
            // a⋅b  = a1b1 + a2b2
            // switch 4 possibles hash value 

            switch (hash & 3)
            {
                case 0: return x + y;
                case 1: return -x + y;
                case 2: return x - y;
                case 3: return -x + -y;
                default: return 0;
            }
        }
    }
}


