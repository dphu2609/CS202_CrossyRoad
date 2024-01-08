#include <Menu/HighScore.hpp>

HighScore::HighScore()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    // sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sf::FloatRect size;

    // mTime=sf::Time::Zero;
    // timePerFrame=sf::seconds(60.f/60.f);

    // lightScreen=true;

    // backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    // backgroundLightSprite.setTexture(backgroundLight);
    // sf::FloatRect sizeThemeOrigin=backgroundLightSprite.getGlobalBounds();
    // backgroundLightSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    // backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    // backgroundLight2Sprite.setTexture(backgroundLight2);
    // sizeThemeOrigin=backgroundLight2Sprite.getGlobalBounds();
    // backgroundLight2Sprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));
    // backgroundLight2Sprite.setPosition(1920.f,0.f);

    _font.loadFromFile("media/font/Alinore.otf");
    colorCharacter=sf::Color(240,246,204); //(240,246,204) (212,240,204)

    aboveBound.setSize(sf::Vector2f(1920,295));
    aboveBound.setFillColor(sf::Color(87,184,250));
    aboveBound.setPosition(0.f,0.f);

    bellowBound.setSize(sf::Vector2f(1920,150));
    bellowBound.setFillColor(sf::Color(156, 218, 247));  //White(199, 240, 253) Blue(129, 204, 245) Quite(156, 218, 247)
    bellowBound.setPosition(0.f,935.f);

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color(5,127,131)); // (29,151,29) (246,237,160) (40,151,155) (24,145,149) (5,127,131)
    size=title.getGlobalBounds();
    title.setOrigin(size.width/2,size.height/2);
    title.setPosition(sf::Vector2f(960.f,50.f));
    title.setScale(1.75,0.8);

    returnBound.setSize(sizeBound);
    returnBound.setFillColor(colorBound);
    returnBound.setPosition(50.f,50.f);

    returnImage.loadFromFile("media/images/menu/Back1.png");
    returnImageSprite.setTexture(returnImage);
    size=returnImageSprite.getGlobalBounds();
    returnImageSprite.setOrigin(size.width/2,size.height/2);
    returnImageSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageSprite.setScale(300.f/size.width,300.f/size.height);

    returnImageDark.loadFromFile("media/images/menu/Back2.png");
    returnImageDarkSprite.setTexture(returnImageDark);
    size=returnImageDarkSprite.getGlobalBounds();
    returnImageDarkSprite.setOrigin(size.width/2,size.height/2);
    returnImageDarkSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageDarkSprite.setScale(300.f/size.width,300.f/size.height);

    isReturnOn=false;

    onep.setString("1P");
    onep.setFont(_font);
    onep.setCharacterSize(sizeCharacter);
    onep.setFillColor(colorCharacter);
    size=onep.getGlobalBounds();
    onep.setOrigin(size.width/2,size.height/2);
    onep.setPosition(sf::Vector2f(502.5,205.f));

    twop.setString("2P");
    twop.setFont(_font);
    twop.setCharacterSize(sizeCharacter);
    twop.setFillColor(colorCharacter);
    size=twop.getGlobalBounds();
    twop.setOrigin(size.width/2,size.height/2);
    twop.setPosition(sf::Vector2f(1417.5,205.f));

    firstBound.setSize(sf::Vector2f(865.f,630.f));
    firstBound.setFillColor(colorBound);
    firstBound.setOutlineThickness(5.0);
    firstBound.setOutlineColor(sf::Color::Green);
    firstBound.setPosition(70.f,300.f);

    secondBound.setSize(sf::Vector2f(865.f,630.f));
    secondBound.setFillColor(colorBound);
    secondBound.setOutlineThickness(5.0);
    secondBound.setOutlineColor(sf::Color::Green);
    secondBound.setPosition(985.f,300.f);

    modes.push_back("Easy");
    modes.push_back("Medi");
    modes.push_back("Hard");
    modes.push_back("Xtre");

    modeFirst=0;
    modeSecond=0;

    modeOneP.setString(modes[modeFirst]);
    modeOneP.setFont(_font);
    modeOneP.setCharacterSize(sizeCharacter);
    modeOneP.setFillColor(sf::Color(94, 131, 166));
    size=modeOneP.getGlobalBounds();
    modeOneP.setOrigin(size.width/2,size.height/2);
    modeOneP.setPosition(sf::Vector2f(502.5,950.f));

    // leftOneP.setPosition(382.5,985.f);
    // rightOneP.setPosition(622.5,985.f);
    // rightOneP.rotate(180.f);

    triangle.loadFromFile("media/images/menu/Backward1.png");
    triangleDark.loadFromFile("media/images/menu/Backward2.png");

    oneIncreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneIncreaseBound.setFillColor(sf::Color::Transparent);
    size=oneIncreaseBound.getLocalBounds();
    oneIncreaseBound.setOrigin(size.width/2,size.height/2); 
    oneIncreaseBound.setPosition(622.5,985.f); //
    oneIncreaseTriangle.setTexture(triangle);
    size=oneIncreaseTriangle.getGlobalBounds();
    oneIncreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangle.setPosition(622.5,985.f);
    oneIncreaseTriangle.rotate(180.f); //
    oneIncreaseTriangleDark.setTexture(triangleDark);
    size=oneIncreaseTriangleDark.getGlobalBounds();
    oneIncreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangleDark.setPosition(622.5,985.f);
    oneIncreaseTriangleDark.rotate(180.f); //

    oneDecreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneDecreaseBound.setFillColor(sf::Color::Transparent);
    size=oneDecreaseBound.getLocalBounds();
    oneDecreaseBound.setOrigin(size.width/2,size.height/2); 
    oneDecreaseBound.setPosition(382.5,985.f); //
    oneDecreaseTriangle.setTexture(triangle);
    size=oneDecreaseTriangle.getGlobalBounds();
    oneDecreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangle.setPosition(382.5,985.f); //
    oneDecreaseTriangleDark.setTexture(triangleDark);
    size=oneDecreaseTriangleDark.getGlobalBounds();
    oneDecreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangleDark.setPosition(382.5,985.f);

    modeTwoP.setString(modes[modeSecond]);
    modeTwoP.setFont(_font);
    modeTwoP.setCharacterSize(sizeCharacter);
    modeTwoP.setFillColor(sf::Color(94, 131, 166));
    size=modeTwoP.getGlobalBounds();
    modeTwoP.setOrigin(size.width/2,size.height/2);
    modeTwoP.setPosition(sf::Vector2f(1417.5,950.f));

    // leftTwoP.setPosition(1297.5,985.f);
    // rightTwoP.setPosition(1537.5,985.f);
    // rightTwoP.rotate(180.f);

    twoIncreaseBound.setSize(sf::Vector2f(70.f,70.f));
    twoIncreaseBound.setFillColor(sf::Color::Transparent);
    size=twoIncreaseBound.getLocalBounds();
    twoIncreaseBound.setOrigin(size.width/2,size.height/2); 
    twoIncreaseBound.setPosition(1537.5,985.f); //
    twoIncreaseTriangle.setTexture(triangle);
    size=twoIncreaseTriangle.getGlobalBounds();
    twoIncreaseTriangle.setOrigin(size.width/2,size.height/2);
    twoIncreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    twoIncreaseTriangle.setPosition(1537.5,985.f);
    twoIncreaseTriangle.rotate(180.f); //
    twoIncreaseTriangleDark.setTexture(triangleDark);
    size=twoIncreaseTriangleDark.getGlobalBounds();
    twoIncreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    twoIncreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    twoIncreaseTriangleDark.setPosition(1537.5,985.f);
    twoIncreaseTriangleDark.rotate(180.f); //

    twoDecreaseBound.setSize(sf::Vector2f(70.f,70.f));
    twoDecreaseBound.setFillColor(sf::Color::Transparent);
    size=twoDecreaseBound.getLocalBounds();
    twoDecreaseBound.setOrigin(size.width/2,size.height/2); 
    twoDecreaseBound.setPosition(1297.5,985.f); //
    twoDecreaseTriangle.setTexture(triangle);
    size=twoDecreaseTriangle.getGlobalBounds();
    twoDecreaseTriangle.setOrigin(size.width/2,size.height/2);
    twoDecreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    twoDecreaseTriangle.setPosition(1297.5,985.f); //
    twoDecreaseTriangleDark.setTexture(triangleDark);
    size=twoDecreaseTriangleDark.getGlobalBounds();
    twoDecreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    twoDecreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    twoDecreaseTriangleDark.setPosition(1297.5,985.f);

    isOneIncreaseOn=false;
    isOneDecreaseOn=false;
    isTwoIncreaseOn=false;
    isTwoDecreaseOn=false;

    onepText.push_back("data/HighScore1PEasy.txt");
    onepText.push_back("data/HighScore1PMedi.txt");
    onepText.push_back("data/HighScore1PHard.txt");
    onepText.push_back("data/HighScore1PXtre.txt");
    twopText.push_back("data/HighScore2PEasy.txt");
    twopText.push_back("data/HighScore2PMedi.txt");
    twopText.push_back("data/HighScore2PHard.txt");
    twopText.push_back("data/HighScore2PXtre.txt");

    sizeLeftTexts=0;
    sizeRightTexts=0;
    loadLeftTextsFromfile();
    loadRightTextFromFile();
}

// sf::Vector2f HighScore::posBackGroundLight()
// {
//     return backgroundLightSprite.getPosition();
// }

// sf::Vector2f HighScore::posBackGroundLight2()
// {
//     return backgroundLight2Sprite.getPosition();
// }

// void HighScore::setPosBackgroundLight(sf::Vector2f pos)
// {
//     backgroundLightSprite.setPosition(pos);
// }

// void HighScore::setPosBackgroundLight2(sf::Vector2f pos)
// {
//     backgroundLight2Sprite.setPosition(pos);
// } 

// bool HighScore::stateBackgroundLight()
// {
//     return lightScreen;
// }  

// void HighScore::setBackground(bool isBackgoundLight)
// {
//     if (isBackgoundLight)
//     {
//         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
//         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
//     }
//     else
//     {
//         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
//         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
//     }
// }  

void HighScore::previousFirst()
{
    if(modeFirst>0) --modeFirst;
    modeOneP.setString(modes[modeFirst]);
}

void HighScore::nextFirst()
{
    if(modeFirst<3) ++modeFirst;
    modeOneP.setString(modes[modeFirst]);
}

void HighScore::previousSecond()
{
    if(modeSecond>0) --modeSecond;
    modeTwoP.setString(modes[modeSecond]);
}

void HighScore::nextSecond()
{
    if(modeSecond<3) ++modeSecond;
    modeTwoP.setString(modes[modeSecond]);
} 

void HighScore::loadLeftTextsFromfile()
{
    sizeLeftTexts=0;
    leftTexts.clear();
    ifstream fin;
    fin.open(onepText[modeFirst]);
    if(!fin.is_open()) {cout<<"Cannot load"<<endl;return;}
    string file;
    while(!fin.eof())
    {
        getline(fin,file);
        sf::Text tmp;
        leftTexts.push_back(tmp);
        leftTexts[sizeLeftTexts].setString(file);
        leftTexts[sizeLeftTexts].setFont(_font);
        leftTexts[sizeLeftTexts].setCharacterSize(sizeCharacter);
        leftTexts[sizeLeftTexts].setFillColor(colorCharacter);
        leftTexts[sizeLeftTexts].setPosition(200.f,300.f+sizeLeftTexts*100);
        sizeLeftTexts++;
    }
    fin.close();
}

void HighScore::loadRightTextFromFile()
{
    sizeRightTexts=0;
    rightTexts.clear();
    ifstream fin;
    fin.open(twopText[modeSecond]);
    if(!fin.is_open()) {cout<<"Cannot load"<<endl;return;}
    string file;
    while(!fin.eof())
    {
        getline(fin,file);
        sf::Text tmp;
        rightTexts.push_back(tmp);
        rightTexts[sizeRightTexts].setString(file);
        rightTexts[sizeRightTexts].setFont(_font);
        rightTexts[sizeRightTexts].setCharacterSize(sizeCharacter);
        rightTexts[sizeRightTexts].setFillColor(colorCharacter);
        rightTexts[sizeRightTexts].setPosition(1115.f,300.f+sizeRightTexts*100);
        sizeRightTexts++;
    }
    fin.close();
}

int HighScore::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2f mousePosition =mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    sf::FloatRect recBound;
    bool isMouseOn;

    if(event.type==sf::Event::MouseWheelScrolled)
    {
        recBound=firstBound.getGlobalBounds();
        isMouseOn=recBound.contains(mousePosition);
        if(isMouseOn)
        {
            if(sizeLeftTexts)
            {
                float delta = 0;
                delta = event.mouseWheelScroll.delta;
                if (delta < 0 && leftTexts[sizeLeftTexts - 1].getPosition().y + 100 > 930)
                {
                    for (int i = 0; i < sizeLeftTexts; i++)
                    {
                        leftTexts[i].setPosition(leftTexts[i].getPosition().x, leftTexts[i].getPosition().y + delta * 20);
                    }
                }
                else if (delta > 0 && leftTexts[0].getPosition().y < 300)
                {
                    for (int i = 0; i < sizeLeftTexts; i++)
                    {
                        leftTexts[i].setPosition(leftTexts[i].getPosition().x, leftTexts[i].getPosition().y + delta * 20);
                    }
                }
            }
            return 2;
        }
        else
        {
            recBound = secondBound.getGlobalBounds();
            isMouseOn = recBound.contains(mousePosition);
            if (isMouseOn)
            {
                if (sizeRightTexts)
                {
                    float delta = 0;
                    delta = event.mouseWheelScroll.delta;
                    if (delta < 0 && rightTexts[sizeRightTexts - 1].getPosition().y + 100 > 930)
                    {
                        for (int i = 0; i < sizeRightTexts; i++)
                        {
                            rightTexts[i].setPosition(rightTexts[i].getPosition().x, rightTexts[i].getPosition().y + delta * 20);
                        }
                    }
                    else if (delta > 0 && rightTexts[0].getPosition().y < 300)
                    {
                        for (int i = 0; i < sizeRightTexts; i++)
                        {
                            rightTexts[i].setPosition(rightTexts[i].getPosition().x, rightTexts[i].getPosition().y + delta * 20);
                        }
                    }
                }
                return 2;
            }
        }
    }

    recBound = returnBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isReturnOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            isReturnOn = false;
            return 0;
        }
        return 2;
    }
    else
    {
        isReturnOn = false;
    }

    recBound = oneDecreaseBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isOneDecreaseOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            previousFirst();
            loadLeftTextsFromfile();
        }
        return 2;
    }
    else
    {
        isOneDecreaseOn = false;
    }

    recBound = oneIncreaseBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isOneIncreaseOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            nextFirst();
            loadLeftTextsFromfile();
        }
        return 2;
    }
    else
    {
        isOneIncreaseOn = false;
    }

    recBound = twoDecreaseBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isTwoDecreaseOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            previousSecond();
            loadRightTextFromFile();
        }
        return 2;
    }
    else
    {
        isTwoDecreaseOn = false;
    }

    recBound = twoIncreaseBound.getGlobalBounds();
    isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isTwoIncreaseOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            nextSecond();
            loadRightTextFromFile();
        }
        return 2;
    }
    else
    {
        isTwoIncreaseOn = false;
    }

    return 2;
}

void HighScore::update(sf::Time dt)
{
    // mTime+=dt;
    // if(mTime>timePerFrame){
    //     if (lightScreen)
    //     {
    //         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains.png");
    //         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains.png");
    //     }
    //     else
    //     {
    //         backgroundLight.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    //         backgroundLight2.loadFromFile("media/images/menu/background_glacial_mountains_lightened.png");
    //     }
    //     lightScreen = !lightScreen;
    //     mTime=sf::Time::Zero;
    // }
    // backgroundLightSprite.setPosition(backgroundLightSprite.getPosition().x-0.5,0.f);
    // backgroundLight2Sprite.setPosition(backgroundLight2Sprite.getPosition().x-0.5,0.f);
    // if(backgroundLight2Sprite.getPosition().x==0.f)
    // {
    //     backgroundLightSprite.setPosition(0.f,0.f);
    //     backgroundLight2Sprite.setPosition(1920.f,0.f);
    // }
}

void HighScore::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);

    for(int i=0;i<sizeLeftTexts;i++)
    {
        mWindow.draw(leftTexts[i]);
    }

    for(int i=0;i<sizeRightTexts;i++)
    {
        mWindow.draw(rightTexts[i]);
    }

    mWindow.draw(aboveBound);
    mWindow.draw(bellowBound);

    mWindow.draw(title);
    mWindow.draw(onep);
    mWindow.draw(twop);
    mWindow.draw(firstBound);
    mWindow.draw(secondBound);

    mWindow.draw(modeOneP);
    mWindow.draw(oneIncreaseBound);
    if(isOneIncreaseOn)
    {
        mWindow.draw(oneIncreaseTriangleDark);
    }
    else mWindow.draw(oneIncreaseTriangle);
    mWindow.draw(oneDecreaseBound);
    if(isOneDecreaseOn)
    {
        mWindow.draw(oneDecreaseTriangleDark);
    }
    else mWindow.draw(oneDecreaseTriangle);

    mWindow.draw(modeTwoP);
    mWindow.draw(twoIncreaseBound);
    if(isTwoIncreaseOn)
    {
        mWindow.draw(twoIncreaseTriangleDark);
    }
    else mWindow.draw(twoIncreaseTriangle);
    mWindow.draw(twoDecreaseBound);
    if(isTwoDecreaseOn)
    {
        mWindow.draw(twoDecreaseTriangleDark);
    }
    else mWindow.draw(twoDecreaseTriangle);

    mWindow.draw(returnBound);
    if(isReturnOn)
    {
        mWindow.draw(returnImageDarkSprite);
    }
    else
    {
        mWindow.draw(returnImageSprite);
    }
}