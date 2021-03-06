﻿#ifndef DBCC_FACTORY_H
#define DBCC_FACTORY_H

#include "DragonBonesHeaders.h"
#include "DBCCRenderHeaders.h"
#include "cocos2d.h"

class DBCCFactory;
class DBCCArmature;
class DBCCSlot;

NAME_SPACE_DRAGON_BONES_BEGIN
class DBCCFactory : public BaseFactory
{
public:
    static DBCCFactory factory;
    
public:
    static DBCCFactory* getInstance();
    
    DBCCFactory();
    virtual ~DBCCFactory();

    virtual DBCCArmature* buildArmature(const String &armatureName) const override;
    virtual DBCCArmature* buildArmature(const String &armatureName, const String &dragonBonesName) const override;
    virtual DBCCArmature* buildArmature(const String &armatureName, const String &skinName, const String &animationName, const String &dragonBonesName, const String &textureAtlasName) const override;
    
    virtual DragonBonesData* loadDragonBonesData(const std::string &dragonBonesFile, const std::string &name = "");
    virtual ITextureAtlas* loadTextureAtlas(const std::string &textureAtlasFile, const std::string &name = "");
    virtual void refreshTextureAtlasTexture(const std::string &name);
    virtual void refreshAllTextureAtlasTexture();
    virtual bool hasDragonBones(const std::string &skeletonName, const std::string &armatureName = "", const std::string &animationName = "");
    
protected:
    virtual DBCCArmature* generateArmature(const ArmatureData *armatureData) const override;
    virtual DBCCSlot* generateSlot(const SlotData *slotData) const override;
    virtual void* generateDisplay(const ITextureAtlas *textureAtlas, const TextureData *textureData, const DisplayData *displayData) const override;
    
private:
    DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(DBCCFactory);
};
NAME_SPACE_DRAGON_BONES_END

#endif  // DBCC_FACTORY_H