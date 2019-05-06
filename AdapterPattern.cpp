//#include <iostream>
//using namespace std;
//class MediaPlayer{
//public:
//    MediaPlayer(){
//    }
//    virtual void play(string audioType, string fileName)=0;
//};
//class AdvanceAudioPlayer{
//public:
//    AdvanceAudioPlayer(){}
//    virtual void playMP4Audio(string name)=0;
//    virtual void playFLACAudio(string name)=0;
//};
//class MP4Player:public  AdvanceAudioPlayer{
//public:
//    MP4Player():AdvanceAudioPlayer(){}
//    void playMP4Audio(string name){
//        cout << "Playing MP4 File"<< endl;
//        cout << "File Name : " << name << endl;
//        cout << endl;
//    }
//    void playFLACAudio(string name){}
//};
//class FLACPlayer:public  AdvanceAudioPlayer{
//public:
////    FLACPlayer():AdvanceAudioPlayer(){}
//    void playFLACAudio(string name){
//        cout << "Playing MP4 File"<< endl;
//        cout << "File Name : " << name << endl;
//        cout << endl;
//    }
//    void playMP4Audio(string name){}
//};
//class AudioPlayerAdapter:public MediaPlayer{
//private:
//    AdvanceAudioPlayer * aap;
//public:
//    AudioPlayerAdapter():MediaPlayer(){
//    }
//    void play(string audioType, string fileName){
//
//        if(audioType == "MP4"){
//            aap = new MP4Player();
//            aap->playMP4Audio(fileName);
//        }else{
//            aap = new FLACPlayer();
//            aap->playFLACAudio(fileName);
//        }
//    }
//};
//class MP3AudioPlayer:public MediaPlayer{
//protected:
//    AudioPlayerAdapter* apAdapter;
//public:
//    MP3AudioPlayer():MediaPlayer(){
//    }
//    void play(string audioType, string fileName){
//        if(audioType == "MP3"){
//            cout << "Playing MP3 File"<< endl;
//            cout << "File Name : " << fileName << endl;
//            cout << endl;
//        }else if(audioType == "MP4" || audioType == "FLAC"){
//            apAdapter = new AudioPlayerAdapter();
//            apAdapter->play(audioType,fileName);
//        }else{
//            cout << "Invalid Format!" << endl;
//            cout << endl;
//        }
//    }
//};
//int main(){
//    MediaPlayer* mp3Player = new MP3AudioPlayer();
//    mp3Player->play("MP3","Bury_A_Friend.mp3");
//    mp3Player->play("MP4","Bury_A_Friend.mp4");
//    mp3Player->play("FLAC","Bury_A_Friend.flac");
//    mp3Player->play("3GP","Bury_A_Friend.3GP");
//}