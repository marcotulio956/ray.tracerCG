#include "scene/Scene.h"
#include "raytracer.h"
#include "io/input.h"
#include "io/output.h"
#include <iostream>
#include <sstream>
using namespace std;

#define WIDTH 800
#define HEIGHT 600

void printHelp()
{
    cout << "Funcionamento do programa:" << '\n'
         << '\n'
         << "- Windows:" << '\n'
         << "\t raytracer.exe arquivo-de-cena.txt" << '\n'
         << '\n'
         << "- Linux/OSX:" << '\n'
         << "\t ./raytracer arquivo-de-cena.txt" << '\n'
         << '\n'
         << '\n'
         << "Possivelmente o programa foi executado sem o devido parâmetro" << '\n'
         << endl;
}

string baseFileName(string const& path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

string removeExtension(string const& filename)
{
    const int p = filename.find_last_of('.');
    return p > 0 ? filename.substr(0, p) : filename;
}

int main(int argc, char* argv[])
{
    // Carrega cena do arquivo cujo nome foi passado como o primeiro parâmetro
    if (argc < 2)
    {
        printHelp();
        return 0;
    }
    string fileName = string(argv[1]);
    Scene s = loadSceneFromFile(fileName);
    RayTracer raytracer;


    // Matriz de pixels que serão "coloridos"
    Vector3** pixels = new Vector3*[HEIGHT];
    for (int i = 0; i < HEIGHT; i++)
    {
        pixels[i] = new Vector3[WIDTH];
    }
    raytracer.renderScene(s, pixels, HEIGHT, WIDTH);


    // Transforma os pixels de double (0..1) para byte (0..255)
    unsigned char* buffer = new unsigned char[HEIGHT * (3 * WIDTH)];
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int invertedI = HEIGHT - i - 1;
            int invertedJ = WIDTH - j - 1;
            Vector3* p = &(pixels[i][j]);
            int index = invertedI * WIDTH * 3 + invertedJ * 3;
            buffer[index + 0] = min((int)(p->r * 255), 255);
            buffer[index + 1] = min((int)(p->g * 255), 255);
            buffer[index + 2] = min((int)(p->b * 255), 255);
        }
    }


    // Escreve um arquivo ppm e outro bmp
    string outputName = removeExtension(baseFileName(string(argv[1])));
    cout << "Salvando arquivos: " << outputName << ".png" << endl;
    stringstream bmp, ppm, png;
    png << outputName << string(".png");
    // bmp << outputName << string(".bmp");
    // ppm << outputName << string(".ppm");

    writeImagePng(png.str().c_str(), WIDTH, HEIGHT, buffer);
    // writeImageBmp(bmp.str().c_str(), WIDTH, HEIGHT, buffer);
    // writeImagePpm(ppm.str().c_str(), WIDTH, HEIGHT, buffer);

    return 0;
}
