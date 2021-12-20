#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <thread>
//#include <chrono>
#include <iostream>

//using namespace std::chrono_literals;
using namespace sf;

class chel 
{
public:
    Sprite tarachkov;
    int dir = 0;
    float x, y, vx, vy, speed = 0;
    chel(int X, int Y, String NAME)
    {
        x = X;
        y = Y;
        name = NAME;
        image.loadFromFile("image/" + name);
        texture.loadFromImage(image);
        tarachkov.setTexture(texture);
        tarachkov.setPosition(x, y);
        tarachkov.setOrigin(45, 60);
    }
    ~chel()
    {
     
    }
    void dvig(float time, int w, int h)
    {
        switch (dir)
        {
            case 0:
                vx = -speed; 
                vy = 0; 
                break;     //влево
            case 1: 
                vx = speed;
                vy = 0; 
                break;     //вправо
            case 2: 
                vx = 0; 
                vy = -speed; 
                break;     //вверх
            case 3: 
                vx = 0; 
                vy = speed; 
                break;     //вниз
        }
        x += vx * time;
        y += vy * time;
        if (x > w)
        {
            x = 0;
        }
        if (x < 0)
        {
            x = w;
        }
        if (y > h)
        {
            y = 0;
        }
        if (y < 0)
        {
            y = h;
        }
        speed = 0;
        tarachkov.setPosition(x, y);
    }
private:
    String name;
    Image image;
    Texture texture;
};

int main()
{
    int w = 1020;
    int h = 600;

    Texture background;
    background.loadFromFile("background.jpg");
    Sprite back(background);

    //SoundBuffer Buffer;    //создаём буфер для звука
   // Buffer.loadFromFile("wood5.wav");  //загружаем в него звук
    //Sound shag(Buffer);

    RenderWindow window(VideoMode(w, h), "mihail vladimirovich begaet!!!!!!");
    Clock clock;
   
    chel mihail(100, 100, "tarachkov.png");

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            mihail.dir = 0;
            mihail.speed = 0.5;
            //shag.play();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            mihail.dir = 1;
            mihail.speed = 0.5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            mihail.dir = 2;
            mihail.speed = 0.5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            mihail.dir = 3;
            mihail.speed = 0.5;
        }

        mihail.dvig(time, w, h);
        window.clear();
        window.draw(back);
        //window.clear();
        window.draw(mihail.tarachkov);
        window.display();

 


    }


    return 0;
}