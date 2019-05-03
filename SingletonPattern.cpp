#include <iostream>
using namespace std;
class GameSetting{
private:
    static GameSetting* instance;
    int brightness;
    GameSetting(int brightness){
        this->brightness = brightness;
    }
public:
    static GameSetting* getInstance(){
        if(instance != NULL){
            return instance;
        }else{
            instance = new GameSetting(50);
            return instance;
        }
    }
    void  displayBrightness(){
        cout << brightness << endl;
    }

    void setBrightness(int brightness) {
        GameSetting::brightness = brightness;
    }
};
GameSetting* GameSetting::instance = NULL;
int main(){
    GameSetting* a = GameSetting::getInstance();
    a->displayBrightness();
    a->setBrightness(99);
    GameSetting* b = GameSetting::getInstance();
    b->displayBrightness();
}