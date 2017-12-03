/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2017 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

// #if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
// #include <wx/bitmap.h> //Must be placed first, otherwise we get errors relative to "cannot convert 'const TCHAR*'..." in wx/msw/winundef.h
// #include <wx/panel.h>
// #endif

#include <iostream>

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
#include <wx/bitmap.h>
#endif
#include <SFML/Graphics.hpp>
#include "GDCore/Tools/Localization.h"
#include "GDCpp/Runtime/Project/Object.h"
#include "GDCpp/Runtime/Project/Project.h"
#include "GDCpp/Runtime/RuntimeScene.h"
#include "GDCpp/Runtime/RuntimeGame.h"
#include "GDCpp/Runtime/RuntimeObjectsListsTools.h"
#include "GDCpp/Runtime/Project/InitialInstance.h"
#include "GDCpp/Runtime/Serialization/SerializerElement.h"
#include "GDCpp/Runtime/Polygon2d.h"
#include "GDCpp/Runtime/CommonTools.h"
#include "InstanceWrapperObject.h"

using namespace std;

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
sf::Texture InstanceWrapperObject::edittimeIconImage;
sf::Sprite InstanceWrapperObject::edittimeIcon;
#endif

InstanceWrapperObject::InstanceWrapperObject(gd::String name_) :
    Object(name_)
{

}

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
void InstanceWrapperObject::DrawInitialInstance(gd::InitialInstance & instance, sf::RenderTarget & renderTarget, gd::Project & project, gd::Layout & layout)
{
    edittimeIcon.setPosition(instance.GetX(), instance.GetY());
    renderTarget.draw(edittimeIcon);
}

void InstanceWrapperObject::LoadEdittimeIcon()
{
    edittimeIconImage.loadFromFile("CppPlatform/Extensions/TiledSpriteIcon.png");
    edittimeIcon.setTexture(edittimeIconImage);
}

bool InstanceWrapperObject::GenerateThumbnail(const gd::Project & project, wxBitmap & thumbnail) const
{
    thumbnail = wxBitmap("CppPlatform/Extensions/TiledSpriteIcon.png", wxBITMAP_TYPE_ANY);

    return true;
}
#endif

RuntimeInstanceWrapperObject::RuntimeInstanceWrapperObject(RuntimeScene & scene, const InstanceWrapperObject & instanceWrapperObject) :
    RuntimeObject(scene, instanceWrapperObject),
    _instance(nullptr)
{

}

RuntimeInstanceWrapperObject::~RuntimeInstanceWrapperObject()
{

}

void RuntimeInstanceWrapperObject::SayHello()
{
    cout << "Hello :)" << endl;
}

void RuntimeInstanceWrapperObject::PointingAt()
{
    cout << _instance << endl;
}

void RuntimeInstanceWrapperObject::SetInstance(RuntimeObject * object)
{
    // Do nothing if set the same instance
    if(_instance != object){
        ClearInstance();
        _instance = object;
    }
}

void RuntimeInstanceWrapperObject::ClearInstance()
{
    _instance = nullptr;
}

void RuntimeInstanceWrapperObject::DeleteInstance(RuntimeScene & scene){
    if(_instance != nullptr){
        ClearInstance();
        _instance->DeleteFromScene(scene);
    }
}

bool RuntimeInstanceWrapperObject::CurrentInstance(std::map <gd::String, std::vector<RuntimeObject*> *> pickedObjectLists)
{
    if(_instance == nullptr){
        return false;
    }

    if(pickedObjectLists[_instance->GetName()] != NULL &&
       find(pickedObjectLists[_instance->GetName()]->begin(), pickedObjectLists[_instance->GetName()]->end(), _instance) != pickedObjectLists[_instance->GetName()]->end())
    {
        PickOnly(pickedObjectLists, _instance);
        return true;
    }

    return false;

}

bool RuntimeInstanceWrapperObject::Empty()
{
    return _instance == nullptr;
}

RuntimeObject * RuntimeInstanceWrapperObject::GetInstance()
{
    return _instance;
}

void RuntimeInstanceWrapperObject::OnSetX(float x){
    if(_instance != nullptr){
        _instance->SetX(x);
    }
}

void RuntimeInstanceWrapperObject::OnSetY(float y){
    if(_instance != nullptr){
        _instance->SetY(y);
    }
}

bool RuntimeInstanceWrapperObject::SetAngle(float angle)
{
    if(_instance != nullptr){
        return _instance->SetAngle(angle);
    }

    return false;
};

void RuntimeInstanceWrapperObject::SetWidth(float w)
{
    if(_instance != nullptr){
        _instance->SetWidth(w);
    }
}

void RuntimeInstanceWrapperObject::SetHeight(float h)
{
    if(_instance != nullptr){
        _instance->SetHeight(h);
    }
}

std::vector<Polygon2d> RuntimeInstanceWrapperObject::GetHitBoxes() const
{
    if(_instance != nullptr){
        return _instance->GetHitBoxes();
    }

    return RuntimeObject::GetHitBoxes();
}

std::vector<Polygon2d> RuntimeInstanceWrapperObject::GetHitBoxes(sf::FloatRect hint) const
{
    if(_instance != nullptr){
        return _instance->GetHitBoxes(hint);
    }

    return RuntimeObject::GetHitBoxes(hint);
}

void RuntimeInstanceWrapperObject::SetZOrder(int z)
{
    if(_instance != nullptr){
        _instance->SetZOrder(z);
    }
}

void RuntimeInstanceWrapperObject::AddForce(float x, float y, float clearing)
{
    if(_instance != nullptr){
        _instance->AddForce(x, y, clearing);
    }
}

void RuntimeInstanceWrapperObject::AddForceUsingPolarCoordinates(float angle, float length, float clearing)
{
    if(_instance != nullptr){
        _instance->AddForceUsingPolarCoordinates(angle, length, clearing);
    }
}

void RuntimeInstanceWrapperObject::AddForceTowardPosition(float x, float y, float length, float clearing)
{
    if(_instance != nullptr){
        _instance->AddForceTowardPosition(x, y, length, clearing);
    }
}

void RuntimeInstanceWrapperObject::AddForceToMoveAround(float x, float y, float angularVelocity, float distance, float clearing)
{
    if(_instance != nullptr){
        _instance->AddForceToMoveAround(x, y, angularVelocity, distance, clearing);
    }
}

bool RuntimeInstanceWrapperObject::ClearForce()
{
    if(_instance != nullptr){
        return _instance->ClearForce();
    }

    return true;
}

float RuntimeInstanceWrapperObject::TotalForceX() const
{
    if(_instance != nullptr){
        return _instance->TotalForceX();
    }

    return 0;
}

float RuntimeInstanceWrapperObject::TotalForceY() const
{
    if(_instance != nullptr){
        return _instance->TotalForceY();
    }

    return 0;
}

bool RuntimeInstanceWrapperObject::VariableExists(const gd::String & variable)
{
    if(_instance != nullptr){
        return _instance->VariableExists(variable);
    }

    return objectVariables.Has(variable);
}

void RuntimeInstanceWrapperObject::SetHidden(bool hide)
{
    if(_instance != nullptr){
        _instance->SetHidden(hide);
    }
}

void RuntimeInstanceWrapperObject::SetLayer(const gd::String & layer_)
{
    if(_instance != nullptr){
        _instance->SetLayer(layer_);
    }
}

void RuntimeInstanceWrapperObject::ActivateBehavior(const gd::String & behaviorName, bool activate)
{
    if(_instance != nullptr){
        _instance->ActivateBehavior(behaviorName, activate);
    }
}

bool RuntimeInstanceWrapperObject::BehaviorActivated(const gd::String & behaviorName)
{
    if(_instance != nullptr){
        return _instance->BehaviorActivated(behaviorName);
    }

    return false;
}
