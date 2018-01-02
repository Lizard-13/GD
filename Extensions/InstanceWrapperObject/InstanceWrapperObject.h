/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#ifndef INSTANCEWRAPPEROBJECT_H
#define INSTANCEWRAPPEROBJECT_H

#include "GDCpp/Runtime/Project/Object.h"
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

#endif // INSTANCEWRAPPEROBJECT_H
