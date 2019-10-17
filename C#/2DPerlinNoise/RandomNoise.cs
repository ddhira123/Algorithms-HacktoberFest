using System;

namespace ImprovedPerlinNoise
{
    class RandomNoise
    {
        static int noiseHeight;
        static int noiseWidth;
        static double[,] noise = GenerateNoise();

        public RandomNoise (int height, int width) {
            noiseHeight = height;
            noiseWidth = width;
        }

        public static double[,] GenerateNoise()
        {
            noise = new double[noiseHeight, noiseWidth];
            Random random = new Random();
            for (int y = 0; y < noiseHeight; y++)
            {
                for (int x = 0; x < noiseWidth; x++)
                {
                    noise[y,x] = random.NextDouble();
                }
            }
            return noise;
        }

        public static double[,] Marble(double twist, double turbulence)
        {
            GenerateNoise();
            // "twist" turbulence power that make it look twirl
            // "turbulence" size of the turbulence
            // "xPeriod" defines repetition of marble lines in x direction
            // "yPeriod" defines repetition of marble lines in y direction
            // xPeriod and yPeriod together define the angle of the lines
            // xPeriod and yPeriod both 0 -> it becomes a normal clouds or turbulence pattern
            // twist = 0 -> it becomes a normal sine pattern

            // I will just use fix value for now
            double xPeriod = 8.0; 
            double yPeriod = 16.0; 
                                   
            Random random = new Random();
            for (int y = 0; y < noiseHeight; y++)
            {
                for (int x = 0; x < noiseWidth; x++)
                {
                    double xyValue = x * xPeriod / noiseWidth + y * yPeriod / noiseHeight + twist * Turbulence(x, y, turbulence) / 255.0;
                    double sineValue = Math.Abs(Math.Sin(xyValue * Math.PI));
                    noise[y, x] = sineValue;
                }
            }
            return noise;
        }

        static double Turbulence(double x, double y, double size)
        {
            double value = 0.0, initialSize = size;

            while (size >= 1)
            {
                value += SmoothNoise(x / size, y / size) * size;
                size /= 2.0;
            }

            return (128.0 * value / initialSize);
        }
        static double SmoothNoise(double x, double y)
        {
            // Get fractional part of x and y
            double xf = x - (int)x;
            double yf = y - (int)y;

            // Wrap around
            int x1 = ((int)x + noiseWidth) % noiseWidth;
            int y1 = ((int)y + noiseHeight) % noiseHeight;

            // Neighbor values
            int x2 = (x1 + noiseWidth - 1) % noiseWidth;
            int y2 = (y1 + noiseHeight - 1) % noiseHeight;

            // Smooth the noise with Bilinear Interpolation
            double value = 0.0;
            value += xf * yf * noise[y1,x1];
            value += (1 - xf) * yf * noise[y1,x2];
            value += xf * (1 - yf) * noise[y2,x1];
            value += (1 - xf) * (1 - yf) * noise[y2,x2];

            return value;
        }

    }
}
