#include <iostream>
#include "Display.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace sf;


void Display::display(std::vector<float> values, std::vector<std::string> names) {
    srand(time((NULL)));


    sf::RenderWindow window(sf::VideoMode(1000, 650), "SFML works!");

    std::vector<sf::RectangleShape> rectangles;
    std::vector<Text> texts;
    std::vector<Text> texts1;

    std::vector<Text> numbers;

    sf::Font font;
    font.loadFromFile("/home/student/oop21_ww_01/project/library/src/font.ttf");

    Text title;
    title.setFont(font);
    title.setCharacterSize(30);
    title.setColor(Color::White);
    title.setStyle(Text::Underlined);
    std::string napis = "Poll results:";
    title.setString(napis);
    title.setPosition( 10 , 10);


    for(int i=0;i<values.size();i++)
    {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(values[i]*7, 750/(2*values.size())));
        sf::Color color(rand()%255, rand()%255, rand()%255);
        rectangle.setFillColor(color);
        rectangle.setOutlineColor(sf::Color::White);
        rectangle.setOutlineThickness(3);
        rectangle.setPosition(200, (750/(values.size()+2))*(i+0.4)+40);
        rectangles.push_back(rectangle);

        Text number;
        number.setFont(font);
        number.setCharacterSize(20);
        number.setColor(color);
        number.setStyle(Text::Bold);
        int a=int(values[i]);
        std::string v = std::to_string(a) + " %";
        number.setString(v);
        number.setPosition( 50 , (750/(values.size()+2))*(i+0.9)+20);
        numbers.push_back(number);

        Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setColor(color );
        text.setStyle(Text::Bold);
        text.setString(names[i]);
        text.setPosition( 50 , (750/(values.size()+2))*(i+0.6)+20);
        texts.push_back(text);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(title);
        for(int i=0;i<rectangles.size();i++)
        {
            window.draw(rectangles[i]);
            window.draw(texts[i]);
            window.draw(numbers[i]);

        }
        for(int i=0;i<rectangles.size();i++)

        window.display();
    }
}