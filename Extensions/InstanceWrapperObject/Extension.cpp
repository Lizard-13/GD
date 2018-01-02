/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#include "GDCpp/Extensions/ExtensionBase.h"

#include "InstanceWrapperObject.h"


void DeclareInstanceWrapperObjectExtension(gd::PlatformExtension & extension)
{
    extension.SetExtensionInformation("InstanceWrapperObject",
                              _("Instance Wrapper Object"),
                              _("This Extension enables the use of Instance Wrapper objects."),
                              "Franco Maciel",
                              "Open source (MIT License)");

    gd::ObjectMetadata & obj = extension.AddObject<InstanceWrapperObject>(
               "InstanceWrapper",
               _("Instance Wrapper"),
               _("Works as a container for another instance, it's like a \"variable object\""),
               "CppPlatform/Extensions/TiledSpriteIcon.png");

    #if defined(GD_IDE_ONLY)
    #if !defined(GD_NO_WX_GUI)
    InstanceWrapperObject::LoadEdittimeIcon();
    #endif
    obj.SetIncludeFile("InstanceWrapperObject/InstanceWrapperObject.h");
    
    obj.AddAction("SetInstance",
                   _("Set instance"),
                   _("Set the wrapper instance."),
                   _("Set _PARAM1_ as current _PARAM0_ instance"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .AddParameter("objectPtr", _("Object"))
        .MarkAsAdvanced();

    obj.AddAction("ClearInstance",
                   _("Clear instance"),
                   _("Clear the wrapper current instance."),
                   _("Clear current instance of _PARAM0_"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced();

    obj.AddCondition("Empty",
                   _("Empty"),
                   _("Check if the wrapper is empty (has no current instance)."),
                   _("_PARAM0_ is empty"),
                   _(""),
                   "res/conditions/scaleWidth24.png",
                   "res/conditions/scaleWidth.png")
        .AddParameter("object", _("Instance Wrapper"), "InstanceWrapper")
        .MarkAsAdvanced();

    extension.AddCondition("CurrentInstance",
                      _("Current instance"),
                      _("Check if the object is the wrapper current instance."),
                      _("_PARAM1_ is the current instance of _PARAM0_"),
                      _(""),
                      "res/conditions/scaleWidth24.png",
                      "res/conditions/scaleWidth.png")
        .AddParameter("objectPtr", _("Instance Wrapper"), "InstanceWrapper")
        .AddParameter("objectList", _("Object"))
        .AddCodeOnlyParameter("conditionInverted", "")
        .MarkAsAdvanced();


    #endif
}
