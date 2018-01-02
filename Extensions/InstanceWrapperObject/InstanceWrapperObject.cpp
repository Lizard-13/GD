/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

// #include <iostream>

#if defined(GD_IDE_ONLY) && !defined(GD_NO_WX_GUI)
#include <wx/bitmap.h>
#endif
#include <SFML/Graphics.hpp>
#include "GDCore/Tools/Localization.h"
#include "GDCpp/Runtime/Project/Object.h"
#include "GDCpp/Runtime/Project/Project.h"
#include "GDCpp/Runtime/Project/InitialInstance.h"
#include "GDCpp/Runtime/Serialization/SerializerElement.h"
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
