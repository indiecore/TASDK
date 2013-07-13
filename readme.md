Tribes Ascend SDK - Unfinished

This repo contains the source for the unofficial Tribes Ascend SDK.
To develop with it and use mods made with it,  you'll need the leaked
Tribes: Ascend developer build. You can download that via the .torrent
included in this repo.

Guidelines and such ==================================================

Minimize global namespace pollution
Maintain coding style

To-do (priority order) ===============================================

Fix garbage in code buffer in ScriptStackFrame - it appears to be valid
UnrealScript bytecode, but seems to be from another call and does not
contain valid args for the hooked function. This prevents grabbing args
from ScriptStackFrame and is top priority.

Automatically grab args off of ScriptStackFrame and pass them to the hook
for more user-friendly hooking. Sort of implemented but the ASM is wrong.

Add automated UnrealScript calls to the generated headers using ProcessEvent.