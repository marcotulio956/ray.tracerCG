CC=g++
OPCOES_COMPILADOR=-Wall -fexceptions -std=c++14 -g -I../cpp
OPCOES_LINKEDITOR=-lm -lstdc++
TODOS_ARQUIVOS_PONTOH = ../*.h ../io/*.h ../io/objects/*.h ../io/pygments/*.h ../math/*.h ../scene/*.h ../scene/objects/*.h ../scene/pygments/*.h ../lib/*.h
TODOS_ARQUIVOS_OBJ = main.o raytracer.o ray.o Light.o Material.o SolidPygment.o CheckerPygment.o TexturePygment.o Scene.o Sphere.o Plane.o Circle.o Triangle.o Cylinder.o vector.o input.o output.o PygmentBuilder.o SolidPygmentFactory.o CheckerPygmentFactory.o TexturePygmentFactory.o ObjectBuilder.o SphereFactory.o PlaneFactory.o CircleFactory.o TriangleFactory.o CylinderFactory.o lodepng.o

%.o: ../%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../scene/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../scene/objects/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../scene/pygments/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../math/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../io/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../io/objects/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../io/pygments/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)
%.o: ../lib/%.cpp $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	$(CC) -o raytracer $^ $(OPCOES_COMPILADOR) $(OPCOES_LINKEDITOR)

run: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-simples.txt)

run-simples: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-simples.txt)

run-primitivas: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-primitivas.txt)

run-2-fontes-luz: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-2-fontes-luz.txt)

run-arvore: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-arvore.txt)

run-empilhadas: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-empilhadas.txt)

run-whitted: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-whitted.txt)

run-cornell-box: all
	(cd ../.. && exec cpp/Makefile/raytracer cena-cornell-box.txt)

clean:
	rm *.o raytracer
