/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2017 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#ifndef INSTANCEWRAPPEROBJECT_H
#define INSTANCEWRAPPEROBJECT_H

#include "GDCpp/Runtime/Project/Object.h"
#include "GDCpp/Runtime/RuntimeObject.h"
class RuntimeScene;
class Polygon2d;
namespace gd { class InitialInstance; }
#if defined(GD_IDE_ONLY)
namespace sf
{
    class Texture;
    class Sprite;
};
namespace gd { class Project; }
class wxBitmap;
#endif

/**
 * Instance Wrapper Object
 */
class GD_EXTENSION_API InstanceWrapperObject : public gd::Object
{
public :
    InstanceWrapperObject(gd::String name_);
    virtual ~InstanceWrapperObject() {};
    virtual std::unique_ptr<gd::Object> Clone() const { return gd::make_unique<InstanceWrapperObject>(*this); }

    #if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
    virtual void DrawInitialInstance(gd::InitialInstance & instance, sf::RenderTarget & renderTarget, gd::Project & project, gd::Layout & layout);
    virtual bool GenerateThumbnail(const gd::Project & project, wxBitmap & thumbnail) const;
    static void LoadEdittimeIcon();
    #endif

private:
    #if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
    static sf::Texture edittimeIconImage;
    static sf::Sprite edittimeIcon;
    #endif
};


class GD_EXTENSION_API RuntimeInstanceWrapperObject : public RuntimeObject
{
public :
    RuntimeInstanceWrapperObject(RuntimeScene & scene, const InstanceWrapperObject & instanceWrapperObject);
    virtual ~RuntimeInstanceWrapperObject();
    virtual std::unique_ptr<RuntimeObject> Clone() const { return gd::make_unique<RuntimeInstanceWrapperObject>(*this);}

    void SayHello();
    void PointingAt();
    void SetInstance(RuntimeObject * object);
    void ClearInstance();
    void DeleteInstance(RuntimeScene & scene);
    bool CurrentInstance(std::map <gd::String, std::vector<RuntimeObject*> *> pickedObjectLists);
    bool Empty();
    RuntimeObject * GetInstance();

    // Position
    inline float GetX() const { return (_instance != nullptr) ? _instance->GetX() : 0; }
    inline float GetY() const { return (_instance != nullptr) ? _instance->GetY() : 0; }
    void OnSetX(float x);
    void OnSetY(float y);
    // Rotation
    inline float GetAngle() const { return (_instance != nullptr) ? _instance->GetAngle() : 0; };
    bool SetAngle(float angle);
    // Scale
    inline float GetWidth() const { return (_instance != nullptr) ? _instance->GetWidth() : 0; };
    inline float GetHeight() const { return (_instance != nullptr) ? _instance->GetHeight() : 0; };
    void SetWidth(float w);
    void SetHeight(float h);
    // Collision
    inline RuntimeObject * GetColliderPtr() { return (_instance != nullptr) ? _instance : this; };
    std::vector<Polygon2d> GetHitBoxes() const;
    std::vector<Polygon2d> GetHitBoxes(sf::FloatRect hint) const;
    // Z-Order
    inline int GetZOrder() const { return (_instance != nullptr) ? _instance->GetZOrder() : 0; }
    void SetZOrder(int z);
    // Forces
    void AddForce(float x, float y, float clearing);
    void AddForceUsingPolarCoordinates(float angle, float length, float clearing);
    void AddForceTowardPosition(float x, float y, float length, float clearing);
    void AddForceToMoveAround(float x, float y, float angularVelocity, float distance, float clearing);
    bool ClearForce();
    float TotalForceX() const;
    float TotalForceY() const;
    // Variables
    inline const RuntimeVariablesContainer & GetVariables() const { return (_instance != nullptr) ? _instance->GetVariables() : objectVariables; }
    inline RuntimeVariablesContainer & GetVariables() { return (_instance != nullptr) ? _instance->GetVariables() : objectVariables; }
    bool VariableExists(const gd::String & variable);
    // Visibility
    inline bool IsHidden() const { return (_instance != nullptr) ? _instance->IsHidden() : hidden; }
    inline bool IsVisible() const { return (_instance != nullptr) ? _instance->IsVisible() : !hidden; }
    void SetHidden(bool hide = true);
    // Layers
    inline const gd::String & GetLayer() const { return (_instance != nullptr) ? _instance->GetLayer() : layer; }
    inline bool IsOnLayer(const gd::String & layer_) const { return (_instance != nullptr) ? _instance->IsOnLayer(layer_) : layer == layer_; }
    inline void SetLayer(const gd::String & layer_);
    // Behaviors
    void ActivateBehavior(const gd::String & behaviorName, bool activate = true);
    bool BehaviorActivated(const gd::String & behaviorName);
  
private:
    RuntimeObject * _instance;
};

#endif // INSTANCEWRAPPEROBJECT_H
