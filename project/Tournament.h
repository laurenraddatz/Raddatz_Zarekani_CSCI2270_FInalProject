#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>


struct Gods{
	std::string name, attribute;
	int health, attack, agility;

	Gods(){};
	Gods(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility)
	{
		name = in_name;
		attribute = in_attribute;
		health = in_health;
		attack = in_attack;
		agility = in_agility;
	}

};

class Tournament
{
    public:
        Tournament();
        ~Tournament();
        void InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility);
        Gods *Fight(Gods *a, Gods *b);
        void printGods();
        void findGod(std::string in_name);
        void playerControl(Gods *a, Gods *b);
        void deleteGod(Gods *a);
        void manualFight(Gods *a, Gods *b);
        void deleteAll();
        void makeGod(std::string in_name, std::string in_attribute, std::string in_dominantStat);

    protected:

    private:
        int godSize = 8;
        Gods *godList[8];
};

#endif // TOURNAMENT_H
