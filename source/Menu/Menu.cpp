#include <Menu/Menu.hpp>

Menu::Menu()
{
    state = 0;
    isPlay = false;
    isBackgroundLight = true;
    posBackgroundLight = sf::Vector2f(0.f, 0.f);
    posBackgroundLight2 = sf::Vector2f(1920.f, 0.f);

    sizeTheme = sf::Vector2f(1920.f, 1080.f);

    mTime = sf::Time::Zero;
    timePerFrame = sf::seconds(60.f / 60.f);

    lightScreen = true;

    backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLightSprite.setTexture(backgroundLight);
    sf::FloatRect sizeThemeOrigin = backgroundLightSprite.getGlobalBounds();
    backgroundLightSprite.setScale(sf::Vector2f(sizeTheme.x / sizeThemeOrigin.width, sizeTheme.y / sizeThemeOrigin.height));

    backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLight2Sprite.setTexture(backgroundLight2);
    sizeThemeOrigin = backgroundLight2Sprite.getGlobalBounds();
    backgroundLight2Sprite.setScale(sf::Vector2f(sizeTheme.x / sizeThemeOrigin.width, sizeTheme.y / sizeThemeOrigin.height));
    backgroundLight2Sprite.setPosition(1920.f, 0.f);
}

bool Menu::playState()
{
    return isPlay;
}

void Menu::returnFromEscapeKey()
{
    isPlay = false;
}

void Menu::processEvent(sf::Event &event, sf::RenderWindow &mWindow)
{
    if (isPlay == false)
    {
        if (state == 0)
        {
            state = mainscreen.processEvent(event, mWindow);
        }
        else if (state == 1)
        {
            state = newgame.processEvent(event, mWindow);
        }
        else if (state == 2)
        {
            state = highscore.processEvent(event, mWindow);
        }
        else if (state == 3)
        {
            state = setting.processEvent(event, mWindow);
        }
        else if (state == 4)
        {
            state = instruction.processEvent(event, mWindow);
        }
        else if (state == 5)
        {
            isPlay = true;
        }
    }
    else
    {
    }
}

void Menu::update(sf::Time dt)
{
    if (isPlay == false)
    {
        mTime += dt;
        if (mTime > timePerFrame)
        {
            if (lightScreen)
            {
                backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
                backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
            }
            else
            {
                backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
                backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
            }
            lightScreen = !lightScreen;
            mTime = sf::Time::Zero;
        }
        backgroundLightSprite.setPosition(backgroundLightSprite.getPosition().x - 0.5, 0.f);
        backgroundLight2Sprite.setPosition(backgroundLight2Sprite.getPosition().x - 0.5, 0.f);
        if (backgroundLight2Sprite.getPosition().x == 0.f)
        {
            backgroundLightSprite.setPosition(0.f, 0.f);
            backgroundLight2Sprite.setPosition(1920.f, 0.f);
        }

        if (state == 0)
        {
            // mainscreen.setBackground(isBackgroundLight);
            // mainscreen.setPosBackgroundLight(posBackgroundLight);
            // mainscreen.setPosBackgroundLight2(posBackgroundLight2);
            mainscreen.update(dt);
            // isBackgroundLight = mainscreen.stateBackgroundLight();
            // posBackgroundLight = mainscreen.posBackGroundLight();
            // posBackgroundLight2 = mainscreen.posBackGroundLight2();
        }
        else if (state == 1)
        {
            // newgame.setBackground(isBackgroundLight);
            // newgame.setPosBackgroundLight(posBackgroundLight);
            // newgame.setPosBackgroundLight2(posBackgroundLight2);
            newgame.update(dt);
            // isBackgroundLight = newgame.stateBackgroundLight();
            // posBackgroundLight = newgame.posBackGroundLight();
            // posBackgroundLight2 = newgame.posBackGroundLight2();
        }
        else if (state == 2)
        {
            // highscore.setBackground(isBackgroundLight);
            // highscore.setPosBackgroundLight(posBackgroundLight);
            // highscore.setPosBackgroundLight2(posBackgroundLight2);
            highscore.update(dt);
            // isBackgroundLight = highscore.stateBackgroundLight();
            // posBackgroundLight = highscore.posBackGroundLight();
            // posBackgroundLight2 = highscore.posBackGroundLight2();
        }
        else if (state == 3)
        {
            // setting.setBackground(isBackgroundLight);
            // setting.setPosBackgroundLight(posBackgroundLight);
            // setting.setPosBackgroundLight2(posBackgroundLight2);
            setting.update(dt);
            // isBackgroundLight = setting.stateBackgroundLight();
            // posBackgroundLight = setting.posBackGroundLight();
            // posBackgroundLight2 = setting.posBackGroundLight2();
        }
        else if (state == 4)
        {
            // instruction.setBackground(isBackgroundLight);
            // instruction.setPosBackgroundLight(posBackgroundLight);
            // instruction.setPosBackgroundLight2(posBackgroundLight2);
            instruction.update(dt);
            // isBackgroundLight = instruction.stateBackgroundLight();
            // posBackgroundLight = instruction.posBackGroundLight();
            // posBackgroundLight2 = instruction.posBackGroundLight2();
        }
    }
    else
    {
    }
}

void Menu::draw(sf::RenderWindow &mWindow)
{
    if (isPlay == false)
    {
        mWindow.draw(backgroundLightSprite);
        mWindow.draw(backgroundLight2Sprite);
        if (state == 0)
        {
            mainscreen.draw(mWindow);
        }
        else if (state == 1)
        {
            newgame.draw(mWindow);
        }
        else if (state == 2)
        {
            highscore.draw(mWindow);
        }
        else if (state == 3)
        {
            setting.draw(mWindow);
        }
        else if (state == 4)
        {
            instruction.draw(mWindow);
        }
    }
    else
    {
    }
}