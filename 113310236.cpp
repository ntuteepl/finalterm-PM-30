#include <iostream>
#include <cmath>
#include <string>
#include<climits>
#include <vector>
using namespace std;

int Le = 1;
bool taunt=false; 
bool boost=false;
int count=1;
class Character {
protected:
    static const int EXP_LV = 100;
    string name;
    int hp;
    int level;
    int exp;
    int attack;
    int mana;
    int dexterity;
    void levelUp(int hInc, int aInc, int mInc, int dInc);
public:
    Character(string n, int lv, int h, int att, int ma, int dex);
    virtual void print();
    virtual void beatMonster(int exp) = 0;
    virtual void setHP(int) = 0;
    virtual int getHP() = 0;
    int getDexterity() const {return dexterity;}
    virtual int getAttack() = 0;
    string getName();
    virtual int getid() = 0;
    virtual int getMana()=0;
    virtual void setMana(int)=0;
};

Character::Character(string n, int lv, int h, int att, int ma, int dex) 
    : name(n), level(lv), exp(pow(lv - 1, 2) * EXP_LV), hp(h), attack(att), mana(ma), dexterity(dex) {}

string Character::getName() {
    return this->name;
}

void Character::levelUp(int hInc, int aInc, int mInc, int dInc) {
    this->level++;
    this->hp += hInc;
    this->attack += aInc;
    this->mana += mInc;
    this->dexterity += dInc;
}

void Character::print() {
    cout << this->name << ": " << this->level << " (" << this->exp << "/" << pow(this->level, 2) * EXP_LV << "), ";
    if (this->hp >= 0)
        cout << this->hp;
    else
        cout << "0";
    cout << "-" << this->attack << "-" << this->mana << "-" << this->dexterity << "\n";
}

class Warrior : public Character {
private:
    static const int HP_LV = 220;
    static const int ATT_LV = 25;
    static const int MANA_LV = 9;
    static const int DEX_LV = 3;
public:
    Warrior(string n, int lv = 1) : Character(n, lv, lv * HP_LV, lv * ATT_LV, lv * MANA_LV, lv * DEX_LV) {}
    void print() { cout << "Warrior "; Character::print(); }
    int getHP() { return hp; }
	int getMana(){return mana;}
	void setMana(int mana){this->mana=mana;}
    void setHP(int hp) { this->hp = hp; }
    int getAttack() { return attack; }
    void beatMonster(int exp) {
        this->exp += exp;
        while (this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(HP_LV, ATT_LV, MANA_LV, DEX_LV);
    }
    int getid(){return 0;}
};

class Wizard : public Character {
private:
    static const int HP_LV = 150;
    static const int ATT_LV = 10;
    static const int MANA_LV = 35;
    static const int DEX_LV = 6;
public:
    Wizard(string n, int lv = 1) : Character(n, lv, lv * HP_LV, lv * ATT_LV, lv * MANA_LV, lv * DEX_LV) {}
    void print() { cout << "Wizard "; Character::print(); }
    int getHP() { return hp; }
    void setHP(int hp) { this->hp = hp; }
    int getAttack() { return attack; }
    int getMana(){return mana;}
    void setMana(int mana){this->mana=mana;}
    void beatMonster(int exp) {
        this->exp += exp;
        while (this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(HP_LV, ATT_LV, MANA_LV, DEX_LV);
    }
    int getid(){return 1;};
};

class Cleric : public Character {
private:
    static const int HP_LV = 145;
    static const int ATT_LV = 7;
    static const int MANA_LV = 42;
    static const int DEX_LV = 10;
public:
    Cleric(string n, int lv = 1) : Character(n, lv, lv * HP_LV, lv * ATT_LV, lv * MANA_LV, lv * DEX_LV) {}
    void print() { cout << "Cleric "; Character::print(); }
    int getHP() { return hp; }
    void setHP(int hp) { this->hp = hp; }
    int getAttack() { return attack; }
    int getMana(){return mana;}
    void setMana(int mana){this->mana=mana;}
    void beatMonster(int exp) {
        this->exp += exp;
        while (this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(HP_LV, ATT_LV, MANA_LV, DEX_LV);
    }
    int getid(){return 2;};
};
class Bolean : public Character {
private:
    static const int HP_LV = 70;
    static const int ATT_LV = 25;
    static const int MANA_LV = 25;
    static const int DEX_LV = 30;
public:
    Bolean(string n, int lv = 1) : Character(n, lv, lv * HP_LV, lv * ATT_LV, lv * MANA_LV, lv * DEX_LV) {}
    void print() { cout << "Bolean "; Character::print(); }
    int getHP() { return hp; }
    void setHP(int hp) { this->hp = hp; }
    int getAttack() { return attack; }
    int getMana(){return mana;}
    void setMana(int mana){this->mana=mana;}
    void beatMonster(int exp) {
        this->exp += exp;
        while (this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(HP_LV, ATT_LV, MANA_LV, DEX_LV);
    }
    int getid(){return 3;};
};

class Monster : public Character {
public:
    Monster(int h, int att, int ma) : Character("Monster", 0, h, att, ma, 0) {}
    void print() { cout << "Monster "; Character::print(); }

    int getHP() { return hp; }

    void setHP(int hp) { this->hp = hp; }
    int getAttack() { return attack; }
    void beatMonster(int exp) {}
    int getid() { return -1;}
    int getMana() { return mana;}
    void setMana(int ma) {}
};
class Team {
protected:
    int memberCount;
    Character* members[10];
public:
    Team();
    ~Team();
    void addWarrior(string name, int lv);
    void addWizard(string name, int lv);
    void addCleric(string name, int lv);
    void addBolean(string name,int lv);
    void memberBeatMonster(string name, int exp);
    void print();
    void combat(Monster* m);
    void offerJoinOptions();
    void Trap();
    void fruit();
};

Team::Team() {
    memberCount = 0;
    for (int i = 0; i < 10; i++)
        members[i] = 0;
}

Team::~Team() {
    for (int i = 0; i < memberCount; i++)
        delete members[i];
}

void Team::addWarrior(string name, int lv) {
    if (memberCount < 10) {
        members[memberCount] = new Warrior(name, lv);
        memberCount++;
    }
}

void Team::addWizard(string name, int lv) {
    if (memberCount < 10) {
        members[memberCount] = new Wizard(name, lv);
        memberCount++;
    }
}

void Team::addCleric(string name, int lv) {
    if (memberCount < 10) {
        members[memberCount] = new Cleric(name, lv);
        memberCount++;
    }
}
void Team::addBolean(string name, int lv) {
    if (memberCount < 10) {
        members[memberCount] = new Bolean(name, lv);
        memberCount++;
    }
}

void Team::memberBeatMonster(string name, int exp) {
    for (int i = 0; i < memberCount; i++) {
        if (members[i]->getName() == name) {
            members[i]->beatMonster(exp);
            break;
        }
    }
}

void Team::print() {
    for (int i = 0; i < memberCount; i++)
        members[i]->print();
}
void Team::fruit(){
    string choice;
    cout<<"選擇吃與不吃\n";
    cout<<"1. 吃 2. 不吃\n";
    cin>>choice;
    if(choice == "1")
    {
        int outcome=rand() % 3;
        if(outcome == 0)
        {
            cout<<"吃到聖果沒事\n";
            for(int i=0;i <memberCount;i++)
            {
                if(members[i]->getHP()>0)
                {
                    members[i]->setHP(members[i]->getHP()+12);
                    members[i]->setMana(members[i]->getMana()+6);
                }
            }
        }
        else if(outcome == 1)
        {
            cout<<"吃到壞掉的水果拉肚子全員受傷\n";
            for(int i=0;i <memberCount;i++)
            {
                if(members[i]->getHP()>0)
                {
                    members[i]->setHP(members[i]->getHP()-6);
                }
            }
        }
        else
        {
            cout<<"吃到一般的果實啥事也沒發生\n";
        }
    }
    else
    {
        cout<<"無事發生\n";
    }
    cout<<"========================\n";
}
void Team::Trap() {
    for (int i = 0; i < memberCount; i++) {
        int avoidChance = rand() % 20 + 1; // 0~20 的隨機數
        if (avoidChance < members[i]->getDexterity()) {
            cout << members[i]->getName() << " 成功避開了陷阱！\n";
            continue;
        }
        int damage = rand() % 10 + 10; // 10~19 點傷害
        members[i]->setHP(max(members[i]->getHP() - damage, 0));
    }
    cout<<"========================\n";
}

void Team::combat(Monster* m) 
{
    int Round = 1;
    while (true) {
        int tauntN = 0, boostN = 0;
        cout << "ROUND " << Round << "\n";
        m->print();
        int aliveCount = 0;

        // 計算存活的隊員
        for (int i = 0; i < memberCount; i++) {
            if (members[i]->getHP() > 0) {
                aliveCount++;
                if(members[i]->getid() == 3 && members[i]->getHP() > 0){
                    aliveCount--;
                }
            }
        }
        int monsterAttack = m->getAttack() / max(1, aliveCount);

        // 處理怪物攻擊，根據taunt影響
        for (int i = 0; i < memberCount; i++) {
            if (members[i]->getHP() > 0) {
                // 如果有角色選擇了taunt，則怪物攻擊集中在該角色
                if (taunt && tauntN > 0) {
                    if (members[i]->getid() == tauntN) {
                        members[i]->setHP(members[i]->getHP() - monsterAttack);  // 只有taunt的角色受到攻擊
                    }
                } else {
                    if(members[i]->getid() == 3 && members[i]->getHP() > 0 && aliveCount > 0){
                        members[i]->setHP(members[i]->getHP()+monsterAttack);
                    }
                    members[i]->setHP(members[i]->getHP() - monsterAttack);  // 普通攻擊
                }
            }
        }

        this->print();
        aliveCount = 0;

        // 更新隊員是否還活著
        for (int i = 0; i < memberCount; i++) {
            if (members[i]->getHP() > 0) {
                aliveCount++;
            }
        }

        // 檢查遊戲是否結束
        if (aliveCount == 0 && m->getHP() > 0) {
            cout << "You Lose，你已死亡\n";
            m->print();
            cout<<"========================\n";
            return;
        }

        int teamAttack = 0;
        bool dance=false;
        for (int i = 0; i < memberCount; i++) {
            if (members[i]->getHP() > 0) {
                int choice = 0;
                cout << "1. 普通攻擊\n";
                if (members[i]->getid() == 0) {
                    cout << "2. 嘲諷\n";
                } else if (members[i]->getid() == 1) {
                    cout << "2. 強化\n";
                } else if (members[i]->getid() == 2) {
                    cout << "2. 治療\n";
                }else if(members[i]->getid() == 3){
                    cout << "2. 跳舞跳舞\n";
                }

                cin >> choice;

                if (choice == 1) {
                    teamAttack += members[i]->getAttack();
                } else if (choice == 2) {
                    if (members[i]->getid() == 0 && members[i]->getMana() >= 3) {
                        members[i]->setMana(members[i]->getMana() - 3);
                        taunt = true; // 嘲諷
                        tauntN++;
                    } else if (members[i]->getid() == 1 && members[i]->getMana() >= 5) {
                        members[i]->setMana(members[i]->getMana() - 5);
                        boost = true; // 增益效果
                        boostN++;
                    } else if (members[i]->getid() == 2 && members[i]->getMana() >= 7) {
                        members[i]->setMana(members[i]->getMana() - 7);
                        for (int j = 0; j < memberCount; j++) {
                            if (members[j]->getHP() > 0) {
                                members[j]->setHP(members[j]->getHP() + 20);  // 治療效果
                            }
                        }    
                    }else if (members[i]->getid() == 3 && members[i]->getMana() >=5){
                        members[i]->setMana(members[i]->getMana()-5); //跳舞效果
                        dance=true;
                        cout<<"哥布林開始開心跳舞\n";      
                    }else{
                        cout << "魔力不足，改為普通攻擊。\n";
                        teamAttack += members[i]->getAttack();
                    }
                }
            }
        }

        // 計算隊伍攻擊，根據boost影響
        if (boost) {
            teamAttack += teamAttack * pow(1.1, boostN); // 增加攻擊力，根據 boostN 數量調整
        }

        // 處理怪物被攻擊
        m->setHP(m->getHP() - teamAttack);
        boost = false;

        // 檢查是否擊敗怪物
        if (m->getHP() <= 0) {
            cout << "Win\n";
            for (int i = 0; i < memberCount; i++) {
                if (members[i]->getHP() > 0) {
                    this->memberBeatMonster(members[i]->getName(), 50 * count); // 提供角色名字和經驗值
                }
            }
            this->print();
            cout<<"你從怪物手上拯救了他人，你可以戴上一個人與你一同冒險\n";
            offerJoinOptions();
            Le++;
            cout<<"========================\n";
            break;
        }
        Round++;
    }
}



void Team::offerJoinOptions() 
{
    int choice;
    cout << "選擇你的夥伴\n";
    cout << "1. Warrior (戰士)\n";
    cout << "2. Wizard (法師)\n";
    cout << "3. Cleric (牧師)\n";
    cout << "請選擇加入的夥伴：\n";
    cin >> choice;

    string name;
    int level;
    if (choice == 1) 
    {
        cout << "請輸入Warrior的名字：\n";
        cin >> name;
        addWarrior(name, Le);
    }
    else if (choice == 2) 
    {
        cout << "請輸入Wizard的名字：\n";
        cin >> name;
        addWizard(name, Le);
    } 
    else if (choice == 3) 
    {
        cout << "請輸入Cleric的名字：\n";
        cin >> name;
        addCleric(name, Le);
    }
    cout<<"你帶領著大家繼續向前邁進";
}

int main()
{
    srand(time(0));
    Team myTeam;
    string name;
    cout<<"來到地下城，";
    cout << "勇者報上名字吧：\n";
    cin >> name;

    int choice;
    cout << "選擇你的職業：\n";
    cout << "1. Warrior (戰士)\n";
    cout << "2. Wizard (法師)\n";
    cout << "3. Cleric (牧師)\n";
    cout << "輸入你所選擇的職業編號(數字就好)：\n";
    cin >> choice;
    

    // 根據選擇職業
    switch (choice) 
    {
        case 1:
            myTeam.addWarrior(name, 1);
            break;
        case 2:
            myTeam.addWizard(name, 1);
            break;
        case 3:
            myTeam.addCleric(name, 1);
            break;
        default:
            cout << "恭喜觸發唯一隱藏職業<哥布林>\n";
            cout << "當你所有隊友死亡時你才會受到傷害\n";
            myTeam.addBolean(name , 1);
    } 
    myTeam.print();

    // 第一場
    cout<<"你在地下城入口遭遇到了怪獸\n";
    Monster m(40, 10, 20);
    myTeam.combat(&m);
    myTeam.print();
    cout<<"獲勝的你前往了下一個關卡\n";
    while(true)
    {
        int currentTurn=(rand() % 6)+1;
        if (currentTurn % 6 == 1) 
        {
            cout << "你在前進的途中遭遇到了怪獸\n";
            Monster newMonster(35* count, 10 * count, 20 * count);
            count++;
            myTeam.combat(&newMonster);
        }
        else if (currentTurn % 6 == 3)
        {
            cout<<"遇到人類夥伴，你戴上了其中一人成為你的夥伴";
            count++;
            myTeam.offerJoinOptions();
        }
        else if(currentTurn % 6 == 4)
        {
            count++;
            cout<<"無事發生，所以你繼續前進";
            cout<<"========================\n";
        }
        else if(currentTurn % 6 == 2)
        {
            cout<<"遇到陷阱有成員可能受傷\n";
            myTeam.Trap();
            myTeam.print();
            cout<<"你帶領剩下依然能活動的人繼續前進\n";
            cout<<"========================\n";
            count++;
        }
        else if(currentTurn % 6 == 0)
        {
            cout<<"遇到聖果全員可能恢復些許的生命值及魔力\n";
            myTeam.fruit();
            count++;
            myTeam.print();
            cout<<"========================\n";
        }
        else if(currentTurn % 6 == 5)
        {
            cout<<"你遭遇到菁英怪\n";
            Monster Boss(50 * pow(count, 1.1), 20 * count + 10, 50 * count);
            myTeam.combat(&Boss);
            count++;
        }
        if (count > 10) 
        {
            cout << "遊戲結束，感謝遊玩！\n";
            break;
        }
    }
    return 0;
}
