/*
意图：提供一个接口以创建一系列相关或相互依赖的对象，而无需指定他们具体的类
*/

#include<map>

using namespace std;

class MapSite {
public:
    virtual void Enter() = 0;
};

class Room : public MapSite {
public:
    Room(int roomNo);
    MapSite* GetSide(int direction) const;
    void SetSide(int direction, MapSite*);

    virtual void Enter();
private:
    MapSite *sides_[4];
    int room_number_;
};


class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void Enter();
    Room* OtherSideFrom(Room*);

private:
    Room* room1_;
    Room* room2_;
    bool is_open_;
};

class Maze {
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;


};