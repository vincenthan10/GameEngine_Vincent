#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, std::string text)
{
    bPressed = false;
    bClicked = false;
    bReleased = false;
    bHighlighted = false;
    //std::memset(this, false, sizeof(Button));

    this->defaultColor = color;
    this->highlightedColor = sf::Color(this->defaultColor.r + 50, this->defaultColor.g + 50, 
        this->defaultColor.b + 50, this->defaultColor.a);

    this->buttonBG.setSize(size);
    this->buttonBG.setFillColor(defaultColor);
    this->buttonBG.setPosition(sf::Vector2f(0, 0));

    this->buttonText.setCharacterSize(11);
    this->buttonText.setFillColor(sf::Color::White);
    this->buttonText.setPosition(sf::Vector2f(0, 0));
    this->buttonText.setString(text);

}

bool Button::isHighlighted()
{
    return bHighlighted;
}

void Button::HighlightedButton(sf::RenderWindow* window)
{
    this->bHighlighted = this->buttonBG.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

    if (bHighlighted == true)
    {
        this->buttonBG.setFillColor(this->highlightedColor);
    }
    else
    {
        this->buttonBG.setFillColor(this->defaultColor);
    }
}

void Button::Update(sf::Event event, float deltaTime)
{
    this->CheckPressed(event);
}

void Button::Render(sf::RenderWindow* window, float deltaTime)
{
    window->draw(this->buttonBG);
    window->draw(this->buttonText);
    window->display();
}

void Button::CheckPressed(sf::Event event)
{
    if (this->bHighlighted == false)
    {
        return;
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        this->bPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if (this->bPressed == false)
        {
            this->bClicked = false;
        }
    }

    if (this->bPressed == true)
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            this->bReleased = true;
            this->bClicked = true;
        }
    }
    else
    {
        this->bReleased = false;
        this->bClicked = false;
    }
}
