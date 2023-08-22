Set wshl = wscript.CreateObject("WScript.Shell")


Sub Sleep(seconds)
  CreateObject("WScript.Shell").Run "%COMSPEC% /c ping 127.0.0.1 -n " _
    & seconds+1, 0, True
End Sub

Sub Delay()
  CreateObject("WScript.Shell").Run "%COMSPEC% /c ping 127.0.0.1", True
End Sub


Sub StartMenue ()
    wshl.SendKeys("^{Esc}") 'start menue by pushing the CTRL ^ and the ESC {Esc}keys
End Sub


Sub ReturnKey ()
    wshl.SendKeys("{ENTER}")
End Sub



Function PressKeys(str)
     wshl.SendKeys(str)
End Function


