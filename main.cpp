#include <iostream>
#include <fstream>

int main()
{
    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::ofstream fout("image.ppm", std::fstream::out);

    fout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            auto r = double(i) / (double(image_width) - 1);
            auto g = double(j) / (double(image_height) - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            fout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    fout.close();

    return 0;
}