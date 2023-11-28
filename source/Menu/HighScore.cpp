#include <Menu/HighScore.hpp>

HighScore::HighScore()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sf::FloatRect size;

    mTime=sf::Time::Zero;
    timePerFrame=sf::seconds(60.f/60.f);

    lightScreen=true;

    backgroundLight.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLightSprite.setTexture(backgroundLight);
    sf::FloatRect sizeThemeOrigin=backgroundLightSprite.getGlobalBounds();
    backgroundLightSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));

    backgroundLight2.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
    backgroundLight2Sprite.setTexture(backgroundLight2);
    sizeThemeOrigin=backgroundLight2Sprite.getGlobalBounds();
    backgroundLight2Sprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));
    backgroundLight2Sprite.setPosition(1920.f,0.f);

    _font.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/font/Alinore.otf");
    colorCharacter=sf::Color::White;

    title.setString("Crossy Road");
    title.setFont(_font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color::Green);
    size=title.getGlobalBounds();
    title.setOrigin(size.width/2,size.height/2);
    title.setPosition(sf::Vector2f(960.f,50.f));
    title.setScale(1.75,0.8);

    returnBound.setSize(sizeBound);
    returnBound.setFillColor(colorBound);
    returnBound.setPosition(50.f,50.f);

    returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back1.png");
    returnImageSprite.setTexture(returnImage);
    size=returnImageSprite.getGlobalBounds();
    returnImageSprite.setOrigin(size.width/2,size.height/2);
    returnImageSprite.setPosition(sf::Vector2f(100.f,100.f));
    returnImageSprite.setScale(300.f/size.width,300.f/size.height);

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

    firstBound.setSize(sf::Vector2f(865.f,730.f));
    firstBound.setFillColor(colorBound);
    firstBound.setOutlineThickness(5.0);
    firstBound.setOutlineColor(sf::Color::Green);
    firstBound.setPosition(70.f,300.f);

    secondBound.setSize(sf::Vector2f(865.f,730.f));
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
    modeOneP.setFillColor(colorCharacter);
    size=modeOneP.getGlobalBounds();
    modeOneP.setOrigin(size.width/2,size.height/2);
    modeOneP.setPosition(sf::Vector2f(502.5,930.f));

    leftOneP.setPosition(382.5,965.f);
    rightOneP.setPosition(622.5,965.f);
    rightOneP.rotate(180.f);

    modeTwoP.setString(modes[modeSecond]);
    modeTwoP.setFont(_font);
    modeTwoP.setCharacterSize(sizeCharacter);
    modeTwoP.setFillColor(colorCharacter);
    size=modeTwoP.getGlobalBounds();
    modeTwoP.setOrigin(size.width/2,size.height/2);
    modeTwoP.setPosition(sf::Vector2f(1417.5,930.f));

    leftTwoP.setPosition(1297.5,965.f);
    rightTwoP.setPosition(1537.5,965.f);
    rightTwoP.rotate(180.f);

    onepText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore1PEasy.txt");
    onepText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore1PMedi.txt");
    onepText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore1PHard.txt");
    onepText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore1PEXtre.txt");
    twopText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore2PEasy.txt");
    twopText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore2PMedi.txt");
    twopText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore2PHard.txt");
    twopText.push_back("D:/GitHub/CS202_CrossyRoad/media/text/HighScore2PXtre.txt");

    sizeLeftTexts=0;
    sizeRightTexts=0;
    loadLeftTextsFromfile();
    loadRightTextFromFile();
}

sf::Vector2f HighScore::posBackGroundLight()
{
    return backgroundLightSprite.getPosition();
}

sf::Vector2f HighScore::posBackGroundLight2()
{
    return backgroundLight2Sprite.getPosition();
}

void HighScore::setPosBackgroundLight(sf::Vector2f pos)
{
    backgroundLightSprite.setPosition(pos);
}

void HighScore::setPosBackgroundLight2(sf::Vector2f pos)
{
    backgroundLight2Sprite.setPosition(pos);
} 

bool HighScore::stateBackgroundLight()
{
    return lightScreen;
}  

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
    if(!fin.is_open()) return;
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
        leftTexts[sizeLeftTexts].setPosition(70.f,300.f+sizeLeftTexts*100);
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
    if(!fin.is_open()) return;
    string file;
    while(!fin.eof())
    {
        getline(fin,file);
        std::cout<<file<<endl;
        sf::Text tmp;
        rightTexts.push_back(tmp);
        rightTexts[sizeRightTexts].setString(file);
        rightTexts[sizeRightTexts].setFont(_font);
        rightTexts[sizeRightTexts].setCharacterSize(sizeCharacter);
        rightTexts[sizeRightTexts].setFillColor(colorCharacter);
        rightTexts[sizeRightTexts].setPosition(985.f,300.f+sizeRightTexts*100);
        sizeRightTexts++;
    }
    fin.close();
}

void HighScore::setBackground(bool isBackgoundLight)
{
    if (isBackgoundLight)
    {
        backgroundLight.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
        backgroundLight2.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
    }
    else
    {
        backgroundLight.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
        backgroundLight2.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
    }
}  

int HighScore::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
    sf::FloatRect recBound=returnBound.getGlobalBounds();
    bool isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back2.png");
        returnImageSprite.setTexture(returnImage);
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            return 0;
        }
    }
    else
    {
        returnImage.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/Back1.png");
        returnImageSprite.setTexture(returnImage);
    }

    recBound=leftOneP.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        leftOneP.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            previousFirst();
            loadLeftTextsFromfile();
        }
    }
    else
    {
        leftOneP.changeToLight();
    }

    recBound=rightOneP.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        rightOneP.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            nextFirst();
            loadLeftTextsFromfile();
        }
    }
    else
    {
        rightOneP.changeToLight();
    }

    recBound=leftTwoP.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        leftTwoP.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            previousSecond();
            loadRightTextFromFile();
        }
    }
    else
    {
        leftTwoP.changeToLight();
    }

    recBound=rightTwoP.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        rightTwoP.changeToDark();
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            nextSecond();   
            loadRightTextFromFile();
        }
    }
    else
    {
        rightTwoP.changeToLight();
    }

    return 2;
}

void HighScore::update(sf::Time dt)
{
    mTime+=dt;
    if(mTime>timePerFrame){
        if (lightScreen)
        {
            backgroundLight.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
            backgroundLight2.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains.png");
        }
        else
        {
            backgroundLight.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
            backgroundLight2.loadFromFile("D:/GitHub/CS202_CrossyRoad/media/images/menu/background_glacial_mountains_lightened.png");
        }
        lightScreen = !lightScreen;
        mTime=sf::Time::Zero;
    }
    backgroundLightSprite.setPosition(backgroundLightSprite.getPosition().x-0.5,0.f);
    backgroundLight2Sprite.setPosition(backgroundLight2Sprite.getPosition().x-0.5,0.f);
    if(backgroundLight2Sprite.getPosition().x==0.f)
    {
        backgroundLightSprite.setPosition(0.f,0.f);
        backgroundLight2Sprite.setPosition(1920.f,0.f);
    }
}

void HighScore::draw(sf::RenderWindow& mWindow)
{
    mWindow.draw(backgroundLightSprite);
    mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(onep);
    mWindow.draw(twop);
    mWindow.draw(firstBound);
    mWindow.draw(secondBound);

    mWindow.draw(modeOneP);
    leftOneP.draw(mWindow);
    rightOneP.draw(mWindow);
    for(int i=0;i<sizeLeftTexts;i++)
    {
        mWindow.draw(leftTexts[i]);
    }

    mWindow.draw(modeTwoP);
    leftTwoP.draw(mWindow);
    rightTwoP.draw(mWindow);
    for(int i=0;i<sizeRightTexts;i++)
    {
        mWindow.draw(rightTexts[i]);
    }

    mWindow.draw(returnBound);
    mWindow.draw(returnImageSprite);
}