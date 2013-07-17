# Tribes Ascend SDK - Unfinished

This repo contains the source for the unofficial Tribes Ascend SDK.
To develop with it and use mods made with it,  you'll need the leaked
Tribes: Ascend developer build. You can download that via the [.torrent](bin.torrent?raw=true)
included in this repo.

## Making maps

1. Download the UDK here: http://download.udk.com/UDKInstall-2011-01-BETA.exe

2. Follow the guide: http://www.reddit.com/r/Tribes/comments/1ia5jb/ta_sdk_the_guide_to_mapping/


## Using the dev build

The `TribesAscend` executable is found under `Binaries\Win32`

To run a local server: 
`TribesAscend mapname (in CookedPC/Maps) -seekfreeloading`

To run a dedicated server: 
`TribesAscend server mapname -seekfreeloading`


## Guidelines

* Minimize global namespace pollution

* Maintain coding style


## TODO list (priority order)

- Add automated UnrealScript calls to the generated headers using ProcessEvent.


  ### Finished

  - Fix garbage in code buffer in ScriptStackFrame - it appears to be valid
  UnrealScript bytecode, but seems to be from another call and does not
  contain valid args for the hooked function. This prevents grabbing args
  from ScriptStackFrame and is top priority.
  
  - Automatically grab args off of ScriptStackFrame and pass them to the hook
  for more user-friendly hooking. Sort of implemented but the ASM is wrong.
  
  - Add a specialized Rotator class.
  
  - Improve implicit conversion between UE3 short vectors and standard float vectors.