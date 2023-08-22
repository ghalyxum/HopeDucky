sub include (fSpec)
    dim fileSys, file, fileData
    set fileSys = createObject ("Scripting.FileSystemObject")
    set file = fileSys.openTextFile (fSpec)
    fileData = file.readAll ()
    file.close
    executeGlobal fileData
    set file = nothing
    set fileSys = nothing
end sub

include "HopeMain.vbs"


' Main Programme

StartMenue()
Delay()
PressKeys("powershell")
Delay()
Delay()
Delay()
Delay()
ReturnKey()
