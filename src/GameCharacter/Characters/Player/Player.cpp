#include "GameCharacter/Characters/Player/Player.h"
void Player::earnExperience(int exp){
    m_exp[0] = exp + m_exp[0];
    while(m_exp[0] >= m_exp[1]){
        m_lvl++;
        m_exp[0]=m_exp[0]-m_exp[1];
        setExperienceCap(m_lvl);
    }
}
void Player::setExperienceCap(int lvl){
    m_exp[1] = pow(m_lvl,3)+99;
}

void Player::print(){
    std::cout << "Experience : " << m_exp[0] <<"/"<<m_exp[1] << std::endl
              << "Level : " << m_lvl << std::endl;
}
Player::~Player()
{
    //dtor
}
