//
//  StageMapView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#ifndef StageMapView_hpp
#define StageMapView_hpp

#include "cocos2d.h"
#include "2d/CCFastTMXTiledMap.h"
#include "MapObjBase.h"

//using namespace cocos2d::experimental;
using namespace cocos2d;

//地图块尺寸大小
#define TILED_SIZE 64
//主角tag
#define PLAYER_TAG 99

//各个层级名称定义
#define ROAD_LAYER "Road"
#define BG_LAYER "BG"
#define OBJ_LAYER "Key"


//对象层对象类型枚举
enum ObjectType {
    OT_PLAYER = 1,     //玩家
    OT_BUILDING = 2,   //建筑
    OT_DISPLAY = 3     //非功能性显示（有遮挡关系的）
};

//点击地图移动时传递的对象（TOUCH_MAP_TO_MOVE）
class Touch2MoveData : public Ref
{
public:
    //目标点
    Point end;
    //建筑id
    int buildId = -1;
};


//class StageMapView : public experimental::TMXTiledMap
class StageMapView : public Node
{
public:
    
    static StageMapView* create(std::string str);
    
    bool init(std::string str);
    
    Vec2 tileCoordForPosition(const Vec2& position);
    // tile坐标转成瓦片格子中心的OpenGL坐标
    Vec2 positionForTileCoord(const Vec2& tileCoord);
    
    TMXTiledMap* getMap();
    //将对象add在地图上， p为在地图上的坐标
    void addToMap(Node *child, Point p);
    //将需要碰撞的对象add进集合
    void addObjToVec(Node *child);
    
private:
    //touch
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
    
private:
    TMXTiledMap* p_tmxMap;
    Vector<Node*> *p_mapObjVec;
};

#endif /* StageMapView_hpp */
