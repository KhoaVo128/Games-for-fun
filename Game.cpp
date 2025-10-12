#include<fstream>
#include<time.h>
#include<iostream>
#include"Game.h"


Game::Game(const std::string & config){
    init(config);
}

void Game::init(const std::string & path){
    std::ifstream fileIn(path);
    std::string temp;
    while(fileIn>>temp){
        if(temp=="Window"){
            int width, height, fps;
            bool fullscreen_mode;
            fileIn
            >>width
            >>height
            >>fps
            >>fullscreen_mode;
            m_window.create(sf::VideoMode(width, height),"Video Game");
            m_window.setFramerateLimit(fps);
        }

        if(temp=="Player"){
            fileIn
            >>m_playerConfig.SR
            >>m_playerConfig.CR
            >>m_playerConfig.FR
            >>m_playerConfig.FG
            >>m_playerConfig.FB
            >>m_playerConfig.OR
            >>m_playerConfig.OG
            >>m_playerConfig.OB
            >>m_playerConfig.OT
            >>m_playerConfig.V
            >>m_playerConfig.S;
        }

        if(temp=="Enemy"){
            fileIn
            >>m_enemyConfig.SR
            >>m_enemyConfig.CR
            >>m_enemyConfig.OR
            >>m_enemyConfig.OG
            >>m_enemyConfig.OB
            >>m_enemyConfig.OT
            >>m_enemyConfig.VMIN
            >>m_enemyConfig.VMAX
            >>m_enemyConfig.L
            >>m_enemyConfig.SI
            >>m_enemyConfig.SMIN
            >>m_enemyConfig.SMAX;
        }
    }
    spawnPlayer();

}

void Game::spawnPlayer(){
    auto entity =  m_entities.addEntities("player");

    float middle_x = m_window.getSize().x/2.0f;
    float middle_y = m_window.getSize().y/2.0f;

    entity->cTransform = std::make_shared<CTransform>(Vec2(middle_x,middle_y), Vec2(1.0f,1.0f), 0.0f);
    entity->cShape = std::make_shared<CShape>(
        m_playerConfig.SR,
        m_playerConfig.V,
        sf::Color(m_playerConfig.FR,m_playerConfig.FG,m_playerConfig.FB),
        sf::Color(m_playerConfig.OR,m_playerConfig.OG,m_playerConfig.OB),
        m_playerConfig.OT
    );
    entity->cInput = std::make_shared<CInput>();
    m_player=entity;

}

void Game::spawnEnemy(){
    auto entity = m_entities.addEntities("enemy");
    
    srand(time(NULL));
    float x= rand()% m_window.getSize().x + m_enemyConfig.SR;
    float y= rand() % m_window.getSize().y + m_enemyConfig.SR;
    int vertices = rand() % m_enemyConfig.VMIN + (m_enemyConfig.VMAX - m_enemyConfig.VMIN);
    entity->cTransform = std::make_shared<CTransform>(Vec2(x,y), Vec2(1.0f,1.0f), 0.0f);
    entity->cShape = std::make_shared<CShape>(
        m_enemyConfig.SR,
        vertices,
        sf::Color(0,0,255),
        sf::Color(m_enemyConfig.OR,m_enemyConfig.OG,m_enemyConfig.OB),
        m_enemyConfig.OT
    ); 
    m_lastEnemySpawnTime=m_currentFrame;


}

void Game::sRender(){
    m_window.clear();
    for(auto e : m_entities.getEntities()){
        e->cShape->circle.setPosition(e->cTransform->position.x, e->cTransform->position.y);
        e->cTransform->angle+=1.0f;
        e->cShape->circle.setRotation(e->cTransform->angle);
        m_window.draw(e->cShape->circle);
    }
    m_window.display();
}

void Game::run(){

    while (m_running){
        m_entities.update();
        sEnemySpawner();
        sCollision();
        sUserInput();
        m_currentFrame++;
    }

    sRender();
    
}

void Game::setPaused(bool paused){
}

void Game::sMovement(){

}

void Game::sUserInput(){

}

void Game::sLifespan(){

}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity){

}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & mousePos){

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity){

}

void Game::sEnemySpawner(){ 
    spawnEnemy();
}

void Game::sCollision(){

}
