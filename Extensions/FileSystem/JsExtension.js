/**
 * This is a declaration of an extension for GDevelop 5.
 *
 * ℹ️ Run `node import-GDJS-Runtime.js` (in newIDE/app/scripts) if you make any change
 * to this extension file or to any other *.js file that you reference inside.
 *
 * The file must be named "JsExtension.js", otherwise GDevelop won't load it.
 * ⚠️ If you make a change and the extension is not loaded, open the developer console
 * and search for any errors.
 *
 * More information on https://github.com/4ian/GDevelop/blob/master/newIDE/README-extensions.md
 */
module.exports = {
  createExtension: function(t, gd) {
    const extension = new gd.PlatformExtension();
    extension
      .setExtensionInformation(
        'FileSystem',
        t('Filesystem'),
        t('Access the filesystem of the operating system.'),
        'Matthias Meike',
        'Open source (MIT License)'
      )
      .setExtensionHelpPath('/all-features/filesystem');

    extension
      .addCondition(
        'PathExists',
        t('File or directory exists'),
        t('Check if the file or directory exists.'),
        t('The path _PARAM0_ exists'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_path_exists24.png',
        'JsPlatform/Extensions/filesystem_path_exists32.png'
      )
      .addParameter('string', t('Path to file or directory'), '', false)
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.pathExists');

    extension
      .addAction(
        'MakeDirectory',
        t('Create a directory'),
        t('Create a new directory at the specified path.'),
        t('Create directory _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_create_folder24.png',
        'JsPlatform/Extensions/filesystem_create_folder32.png'
      )
      .addParameter('string', t('Directory'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.makeDirectory');

    extension
      .addAction(
        'SaveStringToFileSync',
        t('Save a text into a file'),
        t(
          'Save a text into a file. Only use this on small files to avoid any lag or freeze during the the game execution.'
        ),
        t('Save _PARAM0_ into file _PARAM1_'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('string', t('String (text)'), '', false)
      .addParameter('string', t('Save path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.saveStringToFile');

    extension
      .addAction(
        'SaveStringToFileAsync',
        t('Save a text into a file (Async)'),
        t(
          "Save a text into a file asynchronously. Use this for large files to avoid any lag or freeze during game execution. The 'result' variable gets updated when the operation has finished."
        ),
        t('Save _PARAM0_ into file _PARAM1_'),
        t('Filesystem/Windows, Linux, MacOS/Asynchronous'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('string', t('String (text)'), '', false)
      .addParameter('string', t('Save path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.saveStringToFileAsync');

    extension
      .addAction(
        'SaveVariableToJSONFileSync',
        t('Save a scene variable into a JSON file'),
        t(
          'Save a scene variable (including, for structure, all the children) into a file in JSON format. Only use this on small files to avoid any lag or freeze during the the game execution.'
        ),
        t('Save scene variable _PARAM0_ into file PARAM1 as JSON'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Save path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.saveVariableToJSONFile');

    extension
      .addAction(
        'SaveVariableToJSONFileAsync',
        t('Save a scene variable into a JSON file (Async)'),
        t(
          "Save the scene variable (including, for structures, all the children) into a file in JSON format, asynchronously. Use this for large files to avoid any lag or freeze during game execution. The 'result' variable gets updated when the operation has finished."
        ),
        t('Save scene variable _PARAM0_ into file PARAM1 as JSON'),
        t('Filesystem/Windows, Linux, MacOS/Asynchronous'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Save path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.saveVariableToJSONFileAsync');

    extension
      .addAction(
        'LoadStringFromFileAsync',
        t('Load a text from a file (Async)'),
        t(
          "Load a text from a file, asynchronously. Use this for large files to avoid any lag or freeze during game execution. The content of the file will be available in the scene variable after a small delay (usually a few milliseconds). The 'result' variable gets updated when the operation has finished."
        ),
        t('Load text from _PARAM1_ into scene variable _PARAM0_ (Async)'),
        t('Filesystem/Windows, Linux, MacOS/Asynchronous'),
        'JsPlatform/Extensions/filesystem_load_file24.png',
        'JsPlatform/Extensions/filesystem_load_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Load path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.loadStringFromFileAsync');

    extension
      .addAction(
        'LoadStringFromFileSync',
        t('Load a text from a file'),
        t(
          'Load a text from a file. Only use this on small files to avoid any lag or freeze during the the game execution.'
        ),
        t('Load text from _PARAM1_ into scene variable _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_load_file24.png',
        'JsPlatform/Extensions/filesystem_load_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Load path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.loadStringFromFile');

    extension
      .addAction(
        'LoadVariableFromJSONFileSync',
        t('Load a scene variable from a JSON file'),
        t(
          'Load a JSON formatted text from a file and convert it to a scene variable (potentially a structure variable with children). Only use this on small files to avoid any lag or freeze during the the game execution.'
        ),
        t('Load JSON from _PARAM1_ into scene variable _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Load path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.loadVariableFromJSONFile');

    extension
      .addAction(
        'LoadVariableFromJSONFileAsync',
        t('Load a scene variable from a JSON file (Async)'),
        t(
          "Load a JSON formatted text from a file and convert it to a scene variable (potentially a structure variable with children), asynchronously. Use this for large files to avoid any lag or freeze during game execution. The content of the file will be available as a scene variable after a small delay (usually a few milliseconds). The 'result' variable gets updated when the operation has finished."
        ),
        t('Load JSON from _PARAM1_ into scene variable _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS/Asynchronous'),
        'JsPlatform/Extensions/filesystem_save_file24.png',
        'JsPlatform/Extensions/filesystem_save_file32.png'
      )
      .addParameter('scenevar', t('Scene variable'), '', false)
      .addParameter('string', t('Load path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.loadVariableFromJSONFileAsync');

    extension
      .addAction(
        'DeleteFile',
        t('Delete a file'),
        t('Delete a file from the filesystem.'),
        t('Delete the file _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_delete_file24.png',
        'JsPlatform/Extensions/filesystem_delete_file32.png'
      )
      .addParameter('string', t('File path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.deleteFile');

    extension
      .addAction(
        'DeleteFileAsync',
        t('Delete a file (Async)'),
        t('Delete a file from the filesystem asyncrounouse.'),
        t('Delete the file _PARAM0_'),
        t('Filesystem/Windows, Linux, MacOS/Asynchronous'),
        'JsPlatform/Extensions/filesystem_delete_file24.png',
        'JsPlatform/Extensions/filesystem_delete_file32.png'
      )
      .addParameter('string', t('File path'), '', false)
      .addParameter(
        'scenevar',
        t(
          "(Optional) Variable to store the result. 'ok': task was successful, 'error': an error occured."
        ),
        '',
        true
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.deleteFileAsync');

    extension
      .addStrExpression(
        'DesktopPath',
        t('Desktop folder'),
        t('Get the path to the desktop folder.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getDesktopPath');

    extension
      .addStrExpression(
        'DocumentsPath',
        t('Documents folder'),
        t('Get the path to the documents folder.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getDocumentsPath');

    extension
      .addStrExpression(
        'PicturesPath',
        t('Pictures folder'),
        t('Get the path to the pictures folder.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getPicturesPath');

    extension
      .addStrExpression(
        'ExecutablePath',
        t('This games executable folder'),
        t('Get the path to this games executable folder.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getExecutablePath');

    extension
      .addStrExpression(
        'UserdataPath',
        t('Userdata folder (For application settings)'),
        t('Get the path to userdata folder. (For application settings)'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getUserdataPath');

    extension
      .addStrExpression(
        'TempPath',
        t('Temp folder'),
        t('Get the path to temp folder.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .addCodeOnlyParameter('currentScene', '')
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getTempPath');

    extension
      .addStrExpression(
        'PathDelimiter',
        t('Path delimiter'),
        t('Get the operating system agnostic path delimiter.'),
        t('Filesystem/Windows, Linux, MacOS'),
        'JsPlatform/Extensions/filesystem_folder24.png',
        'JsPlatform/Extensions/filesystem_folder32.png'
      )
      .getCodeExtraInformation()
      .setIncludeFile('Extensions/FileSystem/filesystemtools.js')
      .setFunctionName('gdjs.fileSystem.getPathDelimiter');

    return extension;
  },
  runExtensionSanityTests: function(gd, extension) {
    return [];
  },
};
