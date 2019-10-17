using System;
using System.IO;
using System.Drawing;

namespace ImprovedPerlinNoise
{
    public class Program
    {
        public static int Main(string[] args)
        {
            Console.WriteLine("Jetabroad Project");
            Console.WriteLine("Please use the following commands. ex: perlin\n");
            Console.WriteLine("perlin => Generate 2D Image using Improved Perlin Noise algorithm");
            Console.WriteLine("Usage: perlin [width] [height] [numberOfImage] [frequency] ");
            Console.WriteLine("_______________________________\n");
            Console.WriteLine("octave => Generate 2D Image using Improved Perlin Noise algorithm with Octaves");
            Console.WriteLine("Usage: octave [width] [height] [numberOfImage] [octaves] [persistence]");
            Console.WriteLine("_______________________________\n");
            Console.WriteLine("random => Generate 2D Image using Random Noise Array");
            Console.WriteLine("Usage: random [width] [height] [numberOfImage] [pixelate]");
            Console.WriteLine("_______________________________\n");
            Console.WriteLine("marble => Generate 2D Marble Texture");
            Console.WriteLine("Usage: marble [width] [height] [numberOfImage] [twist] [turbulence]");
            Console.WriteLine("_______________________________\n");
            Console.WriteLine("*Images are saved in output folder same directory of ImprovedPerlinNoise.exe\ne.g. \\ImprovedPerlinNoise\\bin\\Debug\\output");
            Console.WriteLine("exit => Exit program\n");

            while (true)
            {
                string[] input = Console.ReadLine().Trim().Split(' ');
                string strFunction = input[0].ToLower();

                if (strFunction == "exit")
                {
                    return 1;
                }
                else if (strFunction == "perlin" || strFunction == "octave" || strFunction == "random" || strFunction == "marble") {
                    try
                    {
                        int index = 1;
                        int width = (index < input.Length) ? Convert.ToInt32(input[1]) : 128; index++;
                        int height = (index < input.Length) ? Convert.ToInt32(input[2]) : 128; index++;
                        int numberOfImage = (index < input.Length) ? Convert.ToInt32(input[3]) : 1; index++;

                        if (width < 1 || height < 1 || numberOfImage < 1)
                        {
                            Console.WriteLine("width, height, and numberOfImage must greater than 0");
                        }
                        else
                        {
                            if (strFunction == "perlin")
                            {
                                int frequency = (index < input.Length) ? Convert.ToInt32(input[4]) : 5;
                                SaveImage(1, width, height, numberOfImage, (frequency > 0) ? frequency : 1);
                            }
                            else if (strFunction == "octave")
                            {
                                int octaves = (index < input.Length) ? Convert.ToInt32(input[4]) : 5; index++;
                                double persistence = (index < input.Length) ? Convert.ToDouble(input[4]) : 0.6;
                                SaveImage(2, width, height, numberOfImage, (octaves > 0) ? octaves : 1, (persistence >= 0) ? persistence : 0);
                            }
                            else if (strFunction == "random")
                            {
                                int pixelate = (index < input.Length) ? Convert.ToInt32(input[4]) : 1;
                                SaveImage(3, width, height, numberOfImage, (pixelate >= 0) ? pixelate : 1);
                            }
                            else if (strFunction == "marble")
                            {
                                double twist = (index < input.Length) ? Convert.ToDouble(input[4]) : 4.0; index++;
                                double turbulence = (index < input.Length) ? Convert.ToDouble(input[5]) : 6.0;
                                SaveImage(4, width, height, numberOfImage, 1, twist, turbulence);
                            }
                        }

                        Console.WriteLine("{0} image was generated", numberOfImage);
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("{0} Exception caught.", e);
                    }
                }
                else
                {
                    Console.WriteLine("Invalid command");
                }
            }
        }

        public static void SaveImage(int function, int width, int height, int numberOfImage, int arg4 = 1, double arg5 = 1, double arg6 = 1)
        {
            string str_Directory = "\\output\\";
            string path = Directory.GetCurrentDirectory() + str_Directory;
            Bitmap img = new Bitmap(width, height);

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }

            for (int num = 0; num < numberOfImage; num++)
            {
                if (function == 1)
                {
                    img = Perlin2DNoiseImage(width, height, arg4);
                }
                else if (function == 2)
                {
                    img = OctavePerlinImage(width, height, arg4, arg5);
                }
                else if (function == 3)
                {
                    img = RandomNoiseImage(width, height, arg4);
                }
                else if (function == 4)
                {
                    img = MarbleImage(width, height, arg5, arg6);
                }
                else
                {
                    img = RandomPixel();
                }

                img.Save(path + DateTime.Now.ToString("yyyyMMddhhmmss_") + num + ".png");
            }
        }

        public static Bitmap Perlin2DNoiseImage(int width, int height, int frequency, bool color = false)
        {
            Bitmap bmp = new Bitmap(width, height);
            Random rand = new Random();
            // Add random effect           
            int random = rand.Next(height);
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    double dx = (double)x / height;
                    double dy = (double)y / height;
                    double noise = PerlinNoise.Perlin2DNoise((dx+ random) * frequency, (dy+ random) * frequency);
                   
                    // Noise value range from -1 to 1, adjust to 0 to 255
                    int value = (int)((noise - 1) / 2 * -255);

                    //Test add color
                    if (color)
                    {
                        //0    red     -> 255,0,0
                        //1    yellow  -> 255,255,0 
                        bmp.SetPixel(x, y, Color.FromArgb(255, 255, value, 0));
                    }
                    else
                    {
                        value = (int)(((noise - 1) / 2) * -255);
                        bmp.SetPixel(x, y, Color.FromArgb(255, value, value, value));
                    }
                }
            }
            return bmp;
        }

        public static Bitmap OctavePerlinImage(int width, int height, int octaves = 5, double persistence = 0.6)
        {
            Bitmap bmp = new Bitmap(width, height);
            Random rand = new Random();
            // Add random effect           
            int random = rand.Next(height);
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    double dx = (double)x / height;
                    double dy = (double)y / height;
                    double noise = PerlinNoise.OctavePerlin(dx + random, dy + random, octaves, persistence);

                    // Noise value range from -1 to 1, adjust to 0 to 255
                    int value = (int)(((noise - 1) / 2) * -255);
                    bmp.SetPixel(x, y, Color.FromArgb(255, value, value, value));
                }
            }
            return bmp;
        }

        public static Bitmap RandomNoiseImage(int width, int height, int pixelate)
        {
            Bitmap bmp = new Bitmap(width, height);
            RandomNoise randomNoise = new RandomNoise(width, height);
            double[,] noise = RandomNoise.GenerateNoise();

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    int value = (int)(noise[x/pixelate, y/pixelate] * 255);
                    bmp.SetPixel(x, y, Color.FromArgb(255, value, value, value));
                }
            }
            return bmp;
        }

        public static Bitmap MarbleImage(int width, int height, double twist, double turbulence)
        {
            Bitmap bmp = new Bitmap(width, height);
            RandomNoise randomNoise = new RandomNoise(width, height);
            double[,] noise = RandomNoise.Marble(twist, turbulence);

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    int value = (int)(noise[x,y] * 255);
                    bmp.SetPixel(x, y, Color.FromArgb(255, value, value, value));
                }
            }
            return bmp;
        }

        // Function for test save image
        public static Bitmap RandomPixel(int width = 128, int height = 128)
        {
            Bitmap bmp = new Bitmap(width, height);
            Random rand = new Random();

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    bmp.SetPixel(x, y, Color.FromArgb(255, rand.Next(256), rand.Next(256), rand.Next(256)));
                }
            }
            return bmp;
        }
    }
}
