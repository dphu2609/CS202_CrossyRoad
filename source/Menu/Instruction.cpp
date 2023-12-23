#include <Menu/Instruction.hpp>
#include <iostream>
using namespace std;
Instruction::Instruction()
{
    colorBound=sf::Color::Transparent;
    sizeBound=sf::Vector2f(100.f,100.f);
    sizeTheme=sf::Vector2f(1000.f,568.f);
    sizePic=sf::Vector2f(2100.f,1182.f);
    sizeX=sf::Vector2f(500.f,500.f);
    sizePodium=sf::Vector2f(1920.f,1080.f);
    sizeCharacter=100;
    sizeCharacterDirection=90;
    sf::FloatRect size;

    numImages=16;
    currentImage=0;
    layout=1;

    cTime=sf::Time::Zero;
    timePerCharacter=sf::seconds(40.f/60.f);

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

    bound.setSize(sf::Vector2f(1780.f,780.f));
    bound.setFillColor(colorBound);
    bound.setOutlineThickness(5.0);
    bound.setOutlineColor(sf::Color::Green);
    bound.setPosition(70.f,200.f);

    part.setString("1/4");
    part.setFont(_font);
    part.setCharacterSize(sizeCharacter);
    part.setFillColor(colorCharacter);
    size=part.getGlobalBounds();
    part.setOrigin(size.width/2,size.height/2);
    part.setPosition(960.f,880.f);

    // left.setPosition(860.f,915.f);
    // right.setPosition(1070.f,915.f);
    // right.rotate(180.f);

    triangle.loadFromFile("media/images/menu/Backward1.png");
    triangleDark.loadFromFile("media/images/menu/Backward2.png");

    oneIncreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneIncreaseBound.setFillColor(sf::Color::Transparent);
    size=oneIncreaseBound.getLocalBounds();
    oneIncreaseBound.setOrigin(size.width/2,size.height/2); 
    oneIncreaseBound.setPosition(1070.f,915.f); //
    oneIncreaseTriangle.setTexture(triangle);
    size=oneIncreaseTriangle.getGlobalBounds();
    oneIncreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangle.setPosition(1070.f,915.f);
    oneIncreaseTriangle.rotate(180.f); //
    oneIncreaseTriangleDark.setTexture(triangleDark);
    size=oneIncreaseTriangleDark.getGlobalBounds();
    oneIncreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneIncreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneIncreaseTriangleDark.setPosition(1070.f,915.f);
    oneIncreaseTriangleDark.rotate(180.f); //

    oneDecreaseBound.setSize(sf::Vector2f(70.f,70.f));
    oneDecreaseBound.setFillColor(sf::Color::Transparent);
    size=oneDecreaseBound.getLocalBounds();
    oneDecreaseBound.setOrigin(size.width/2,size.height/2); 
    oneDecreaseBound.setPosition(860.f,915.f); //
    oneDecreaseTriangle.setTexture(triangle);
    size=oneDecreaseTriangle.getGlobalBounds();
    oneDecreaseTriangle.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangle.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangle.setPosition(860.f,915.f); //
    oneDecreaseTriangleDark.setTexture(triangleDark);
    size=oneDecreaseTriangleDark.getGlobalBounds();
    oneDecreaseTriangleDark.setOrigin(size.width/2,size.height/2);
    oneDecreaseTriangleDark.setScale(220.f/size.width,220.f/size.height);
    oneDecreaseTriangleDark.setPosition(860.f,915.f);

    isOneIncreaseOn=false;
    isOneDecreaseOn=false;

    firstIns.setString("Use keyboards to move");
    firstIns.setFont(_font);
    firstIns.setCharacterSize(50);
    firstIns.setFillColor(colorCharacter);
    size=firstIns.getGlobalBounds();
    firstIns.setOrigin(size.width/2,size.height/2);
    firstIns.setPosition(960.f,280.f);

    leftImageDark.loadFromFile("media/images/menu/leftIns.png");
    leftImageDarkSprite.setTexture(leftImageDark);
    size=leftImageDarkSprite.getGlobalBounds();
    leftImageDarkSprite.setOrigin(size.width/2,size.height/2);
    leftImageDarkSprite.setPosition(sf::Vector2f(740.f,770.f));
    leftImageDarkSprite.setScale(500.f/size.width,500.f/size.height);

    rightImageDark.loadFromFile("media/images/menu/leftIns.png");
    rightImageDarkSprite.setTexture(rightImageDark);
    size=rightImageDarkSprite.getGlobalBounds();
    rightImageDarkSprite.setOrigin(size.width/2,size.height/2);
    rightImageDarkSprite.setPosition(sf::Vector2f(1180.f,760.f));
    rightImageDarkSprite.setScale(500.f/size.width,500.f/size.height);
    rightImageDarkSprite.rotate(180);

    upImageDark.loadFromFile("media/images/menu/upIns.png");
    upImageDarkSprite.setTexture(upImageDark);
    size=upImageDarkSprite.getGlobalBounds();
    upImageDarkSprite.setOrigin(size.width/2,size.height/2);
    upImageDarkSprite.setPosition(sf::Vector2f(960.f,520.f));
    upImageDarkSprite.setScale(500.f/size.width,500.f/size.height);

    up.loadFromFile("media/images/menu/up.png");
    upSprite.setTexture(up);
    size=upSprite.getGlobalBounds();
    upSprite.setOrigin(size.width/2,size.height/2);
    upSprite.setScale(200.f/size.width,200.f/size.height);
    upSprite.setPosition(sf::Vector2f(600.f,300.f));

    down.loadFromFile("media/images/menu/down.png");
    downSprite.setTexture(down);
    size=downSprite.getGlobalBounds();
    downSprite.setOrigin(size.width/2,size.height/2);
    downSprite.setScale(200.f/size.width,200.f/size.height);
    downSprite.setPosition(sf::Vector2f(600.f,410.f));

    right.loadFromFile("media/images/menu/right.png");
    rightSprite.setTexture(right);
    size=rightSprite.getGlobalBounds();
    rightSprite.setOrigin(size.width/2,size.height/2);
    rightSprite.setScale(200.f/size.width,200.f/size.height);
    rightSprite.setPosition(sf::Vector2f(710.f,410.f));

    left.loadFromFile("media/images/menu/left.png");
    leftSprite.setTexture(left);
    size=leftSprite.getGlobalBounds();
    leftSprite.setOrigin(size.width/2,size.height/2);
    leftSprite.setScale(200.f/size.width,200.f/size.height);
    leftSprite.setPosition(sf::Vector2f(490.f,410.f));

    w.loadFromFile("media/images/menu/letterControl.png");
    wSprite.setTexture(w);
    size=wSprite.getGlobalBounds();
    wSprite.setOrigin(size.width/2,size.height/2);
    wSprite.setScale(200.f/size.width,200.f/size.height);
    wSprite.setPosition(sf::Vector2f(1320.f,300.f));

    // wBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // wBound.setFillColor(colorBound);
    // wBound.setPosition(1270.f,250.f);

    s.loadFromFile("media/images/menu/letterControl.png");
    sSprite.setTexture(s);
    size=sSprite.getGlobalBounds();
    sSprite.setOrigin(size.width/2,size.height/2);
    sSprite.setScale(200.f/size.width,200.f/size.height);
    sSprite.setPosition(sf::Vector2f(1320.f,410.f));

    // sBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // sBound.setFillColor(colorBound);
    // sBound.setPosition(1270.f,360.f);

    a.loadFromFile("media/images/menu/letterControl.png");
    aSprite.setTexture(a);
    size=aSprite.getGlobalBounds();
    aSprite.setOrigin(size.width/2,size.height/2);
    aSprite.setScale(200.f/size.width,200.f/size.height);
    aSprite.setPosition(sf::Vector2f(1210.f,410.f));

    // aBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // aBound.setFillColor(colorBound);
    // aBound.setPosition(1160.f,360.f);

    d.loadFromFile("media/images/menu/letterControl.png");
    dSprite.setTexture(d);
    size=dSprite.getGlobalBounds();
    dSprite.setOrigin(size.width/2,size.height/2);
    dSprite.setScale(200.f/size.width,200.f/size.height);
    dSprite.setPosition(sf::Vector2f(1430.f,410.f));

    // dBound.setSize(sf::Vector2f(sizeBound.x,sizeBound.y));
    // dBound.setFillColor(colorBound);
    // dBound.setPosition(1380.f,360.f);

    wText.setString("W");
    wText.setFont(_font);
    wText.setCharacterSize(sizeCharacterDirection);
    wText.setFillColor(colorCharacter);
    size=wText.getGlobalBounds();
    wText.setOrigin(size.width/2,size.height/2);
    wText.setPosition(sf::Vector2f(1318.f,265.f));
    //wText.setScale(1.75,0.8);

    sText.setString("S");
    sText.setFont(_font);
    sText.setCharacterSize(sizeCharacterDirection);
    sText.setFillColor(colorCharacter);
    size=sText.getGlobalBounds();
    sText.setOrigin(size.width/2,size.height/2);
    sText.setPosition(sf::Vector2f(1318.f,375.f));
    //wText.setScale(1.75,0.8);

    aText.setString("A");
    aText.setFont(_font);
    aText.setCharacterSize(sizeCharacterDirection);
    aText.setFillColor(colorCharacter);
    size=aText.getGlobalBounds();
    aText.setOrigin(size.width/2,size.height/2);
    aText.setPosition(sf::Vector2f(1208.f,375.f));

    dText.setString("D");
    dText.setFont(_font);
    dText.setCharacterSize(sizeCharacterDirection);
    dText.setFillColor(colorCharacter);
    size=dText.getGlobalBounds();
    dText.setOrigin(size.width/2,size.height/2);
    dText.setPosition(sf::Vector2f(1428.f,375.f));
    //wText.setScale(1.75,0.8);

    setPlayerTexture();
    //firstPlayer.loadFromFile("media/images/characters/1.png");
    for (int i = 0; i < numImages; i++)
    {
        firstPlayerSprites[i].setTexture(firstPlayers[i]);
        size = firstPlayerSprites[i].getGlobalBounds();
        firstPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        firstPlayerSprites[i].setPosition(sf::Vector2f(960, 680.f));
        firstPlayerSprites[i].setScale(0.6, 0.6);
    }

    //secondPlayer.loadFromFile("media/images/characters/1.png");
    for (int i = 0; i < numImages; i++)
    {
        secondPlayerSprites[i].setTexture(secondPlayers[i]);
        size = secondPlayerSprites[i].getGlobalBounds();
        secondPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        secondPlayerSprites[i].setPosition(sf::Vector2f(960, 730.f));
        secondPlayerSprites[i].setScale(0.6, 0.6);
    }

    secondIns.setString("Go through all lanes");
    secondIns.setFont(_font);
    secondIns.setCharacterSize(50);
    secondIns.setFillColor(colorCharacter);
    size=secondIns.getGlobalBounds();
    secondIns.setOrigin(size.width/2,size.height/2);
    secondIns.setPosition(960.f,570.f);

    laneImage.loadFromFile("media/images/menu/lane3.png");
    laneImageSprite.setTexture(laneImage);
    size=laneImageSprite.getGlobalBounds();
    laneImageSprite.setOrigin(size.width/2,size.height/2);
    sf::FloatRect sizeThemeOrigin=laneImageSprite.getGlobalBounds();
    laneImageSprite.setScale(sf::Vector2f(sizeTheme.x/sizeThemeOrigin.width,sizeTheme.y/sizeThemeOrigin.height));
    laneImageSprite.setPosition(960.f,500.f);

    thirdIns1.setString("Crashed by car");
    thirdIns1.setFont(_font);
    thirdIns1.setCharacterSize(50);
    thirdIns1.setFillColor(colorCharacter);
    size=thirdIns1.getGlobalBounds();
    thirdIns1.setOrigin(size.width/2,size.height/2);
    thirdIns1.setPosition(480.f,335.f);

    thirdIns2.setString("Crashed by train");
    thirdIns2.setFont(_font);
    thirdIns2.setCharacterSize(50);
    thirdIns2.setFillColor(colorCharacter);
    size=thirdIns2.getGlobalBounds();
    thirdIns2.setOrigin(size.width/2,size.height/2);
    thirdIns2.setPosition(1440.f,335.f);

    thirdIns3.setString("Dive into the river");
    thirdIns3.setFont(_font);
    thirdIns3.setCharacterSize(50);
    thirdIns3.setFillColor(colorCharacter);
    size=thirdIns3.getGlobalBounds();
    thirdIns3.setOrigin(size.width/2,size.height/2);
    thirdIns3.setPosition(480.f,660.f);

    thirdIns4.setString("Slide out the screen");
    thirdIns4.setFont(_font);
    thirdIns4.setCharacterSize(50);
    thirdIns4.setFillColor(colorCharacter);
    size=thirdIns4.getGlobalBounds();
    thirdIns4.setOrigin(size.width/2,size.height/2);
    thirdIns4.setPosition(1440.f,660.f);    

    carImage.loadFromFile("media/images/menu/car.png");
    carImageSprite.setTexture(carImage);
    size=carImageSprite.getGlobalBounds();
    carImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=carImageSprite.getGlobalBounds();
    carImageSprite.setScale(sf::Vector2f(sizePic.x/sizeThemeOrigin.width,sizePic.y/sizeThemeOrigin.height));
    carImageSprite.setPosition(480.f,300.f);

    trainImage.loadFromFile("media/images/menu/train.png");
    trainImageSprite.setTexture(trainImage);
    size=trainImageSprite.getGlobalBounds();
    trainImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=trainImageSprite.getGlobalBounds();
    trainImageSprite.setScale(sf::Vector2f(sizePic.x/sizeThemeOrigin.width,sizePic.y/sizeThemeOrigin.height));
    trainImageSprite.setPosition(1440.f,300.f);

    riverImage.loadFromFile("media/images/menu/river.png");
    riverImageSprite.setTexture(riverImage);
    size=riverImageSprite.getGlobalBounds();
    riverImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=riverImageSprite.getGlobalBounds();
    riverImageSprite.setScale(sf::Vector2f(sizePic.x/sizeThemeOrigin.width,sizePic.y/sizeThemeOrigin.height));
    riverImageSprite.setPosition(480.f,600.f);

    outImage.loadFromFile("media/images/menu/out.png");
    outImageSprite.setTexture(outImage);
    size=outImageSprite.getGlobalBounds();
    outImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=outImageSprite.getGlobalBounds();
    outImageSprite.setScale(sf::Vector2f(sizePic.x/sizeThemeOrigin.width,sizePic.y/sizeThemeOrigin.height));
    outImageSprite.setPosition(1440.f,600.f);

    xImage.loadFromFile("media/images/menu/x4.png");
    xImageSprite.setTexture(xImage);
    size=xImageSprite.getGlobalBounds();
    xImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=xImageSprite.getGlobalBounds();
    xImageSprite.setScale(sf::Vector2f(sizeX.x/sizeThemeOrigin.width,sizeX.y/sizeThemeOrigin.height));
    xImageSprite.setPosition(960.f,440.f);

    for (int i = 0; i < numImages; i++)
    {
        thirdPlayerSprites[i].setTexture(thirdPlayers[i]);
        size = thirdPlayerSprites[i].getGlobalBounds();
        thirdPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        thirdPlayerSprites[i].setPosition(sf::Vector2f(480, 450.f));
        thirdPlayerSprites[i].setScale(0.3, 0.3);

        fourthPlayerSprites[i].setTexture(fourthPlayers[i]);
        size = fourthPlayerSprites[i].getGlobalBounds();
        fourthPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        fourthPlayerSprites[i].setPosition(sf::Vector2f(1440, 450.f));
        fourthPlayerSprites[i].setScale(0.3, 0.3);

        fifthPlayerSprites[i].setTexture(fifthPlayers[i]);
        size = fifthPlayerSprites[i].getGlobalBounds();
        fifthPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        fifthPlayerSprites[i].setPosition(sf::Vector2f(480, 780.f));
        fifthPlayerSprites[i].setScale(0.3, 0.3);

        sixthPlayerSprites[i].setTexture(sixthPlayers[i]);
        size = sixthPlayerSprites[i].getGlobalBounds();
        sixthPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        sixthPlayerSprites[i].setPosition(sf::Vector2f(1440, 780.f));
        sixthPlayerSprites[i].setScale(0.3, 0.3);

        seventhPlayerSprites[i].setTexture(seventhPlayers[i]);
        size = seventhPlayerSprites[i].getGlobalBounds();
        seventhPlayerSprites[i].setOrigin(size.width / 2, size.height / 2);
        seventhPlayerSprites[i].setPosition(sf::Vector2f(960, 310.f));
        seventhPlayerSprites[i].setScale(0.4, 0.4);
    }

    fourthIns.setString("Attain the Podium");
    fourthIns.setFont(_font);
    fourthIns.setCharacterSize(50);
    fourthIns.setFillColor(colorCharacter);
    size=fourthIns.getGlobalBounds();
    fourthIns.setOrigin(size.width/2,size.height/2);
    fourthIns.setPosition(960.f,815.f);

    podiumImage.loadFromFile("media/images/menu/podium2.png");
    podiumImageSprite.setTexture(podiumImage);
    size=podiumImageSprite.getGlobalBounds();
    podiumImageSprite.setOrigin(size.width/2,size.height/2);
    sizeThemeOrigin=podiumImageSprite.getGlobalBounds();
    podiumImageSprite.setScale(sf::Vector2f(sizePodium.x/sizeThemeOrigin.width,sizePodium.y/sizeThemeOrigin.height));
    podiumImageSprite.setPosition(960.f,600.f);
}

// sf::Vector2f Instruction::posBackGroundLight()
// {
//     return backgroundLightSprite.getPosition();
// }

// sf::Vector2f Instruction::posBackGroundLight2()
// {
//     return backgroundLight2Sprite.getPosition();
// }

// void Instruction::setPosBackgroundLight(sf::Vector2f pos)
// {
//     backgroundLightSprite.setPosition(pos);
// }

// void Instruction::setPosBackgroundLight2(sf::Vector2f pos)
// {
//     backgroundLight2Sprite.setPosition(pos);
// } 

// bool Instruction::stateBackgroundLight()
// {
//     return lightScreen;
// }  

// void Instruction::setBackground(bool isBackgoundLight)
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

void Instruction::previous()
{
    string tmp=part.getString();
    int current=tmp[0]-'0';
    tmp.erase(tmp.begin());
    if(current>1) {--current;layout=current;}
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}

void Instruction::next()
{
    string tmp=part.getString();
    int current=tmp[0]-'0';
    tmp.erase(tmp.begin());
    if(current<4) {++current;layout=current;}
    tmp=to_string(current)+tmp;
    part.setString(tmp);
}   

void Instruction::setPlayerTexture()
{
    sf::FloatRect size;
    for(int i=1;i<=numImages;i++)
    {
        string link=Link(i).getLink();
        firstPlayer.loadFromFile(link);
        firstPlayers.push_back(firstPlayer);
        secondPlayers.push_back(firstPlayer);
        thirdPlayers.push_back(firstPlayer);
        fourthPlayers.push_back(firstPlayer);
        fifthPlayers.push_back(firstPlayer);
        sixthPlayers.push_back(firstPlayer);
        seventhPlayers.push_back(firstPlayer);
    }
}

int Instruction::processEvent(sf::Event& event,sf::RenderWindow& mWindow)
{
    sf::Vector2f mousePosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    sf::FloatRect recBound = returnBound.getGlobalBounds();
    bool isMouseOn = recBound.contains(mousePosition);
    if (isMouseOn)
    {
        isReturnOn = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            isReturnOn = false;
            return 0;
        }
        return 4;
    }
    else
    {
        isReturnOn = false;
    }

    recBound=oneDecreaseBound.getGlobalBounds();
    isMouseOn=recBound.contains(mousePosition);
    if(isMouseOn)
    {
        isOneDecreaseOn=true;
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            previous();
        }
        return 4;
    }
    else
    {
        isOneDecreaseOn=false;
    }

    recBound=oneIncreaseBound.getGlobalBounds();
    isMouseOn=recBound.contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));
    if(isMouseOn)
    {
        isOneIncreaseOn=true;
        if(event.type==sf::Event::MouseButtonPressed&&event.mouseButton.button==sf::Mouse::Left)
        {
            next();
        }
        return 4;
    }
    else
    {
        isOneIncreaseOn=false;
    }

    return 4;
}

void Instruction::update(sf::Time dt)
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

    cTime+=dt;
    if(cTime>timePerCharacter)
    {
        ++currentImage;
        if(currentImage==numImages) currentImage=0;
        cTime=sf::Time::Zero;
    }
}

void Instruction::draw(sf::RenderWindow& mWindow)
{
    // mWindow.draw(backgroundLightSprite);
    // mWindow.draw(backgroundLight2Sprite);
    mWindow.draw(title);
    mWindow.draw(bound);
    mWindow.draw(part);
    
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

    if (layout == 1)
    {
        mWindow.draw(firstIns);
        mWindow.draw(upSprite);
        mWindow.draw(downSprite);
        mWindow.draw(rightSprite);
        mWindow.draw(leftSprite);
        mWindow.draw(wSprite);
        mWindow.draw(sSprite);
        mWindow.draw(aSprite);
        mWindow.draw(dSprite);
        mWindow.draw(wText);
        mWindow.draw(sText);
        mWindow.draw(aText);
        mWindow.draw(dText);
        mWindow.draw(leftImageDarkSprite);
        mWindow.draw(rightImageDarkSprite);
        mWindow.draw(upImageDarkSprite);
        mWindow.draw(firstPlayerSprites[currentImage]);
    }
    else if(layout==2)
    {
        mWindow.draw(secondIns);
        mWindow.draw(laneImageSprite);
        mWindow.draw(secondPlayerSprites[currentImage]);
    }
    else if(layout==3)
    {
        mWindow.draw(carImageSprite);
        mWindow.draw(trainImageSprite);
        mWindow.draw(riverImageSprite);
        mWindow.draw(outImageSprite);
        mWindow.draw(xImageSprite);
        mWindow.draw(thirdIns1);
        mWindow.draw(thirdIns2);
        mWindow.draw(thirdIns3);
        mWindow.draw(thirdIns4);
        mWindow.draw(thirdPlayerSprites[currentImage]);
        mWindow.draw(fourthPlayerSprites[currentImage]);
        mWindow.draw(fifthPlayerSprites[currentImage]);
        mWindow.draw(sixthPlayerSprites[currentImage]);
    }
    else if(layout==4)
    {
        mWindow.draw(podiumImageSprite);
        mWindow.draw(fourthIns);
        mWindow.draw(seventhPlayerSprites[currentImage]);
    }

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