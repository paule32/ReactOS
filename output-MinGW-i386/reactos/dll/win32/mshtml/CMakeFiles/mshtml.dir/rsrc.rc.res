L     Į       .rsrc           ¬¼  <   č¼      j   @ 0Ą    «(½Y      ą H    x     Ø         P        °     «(½Y       š `      «(½Y           0      «(½Y                «(½Y           @      «(½Y         Č  @        «(½Y          P  
   `     p                     °     Ą     Š  '   ą    š           	       0    @    P    `    p               "  °  $  Ą    Š      «(½Y          ą  
   š                      0     @     P  '   `    p          	       °    Ą    Š    ą    š                  0  "  @  $  P    `    p      «(½Y       Õ    Ų  x     «(½Y            
              °     Ą     Š     ą     š  '    	    	     	    0	  	  @	    P	    `	    p	    	    	     	    °	    Ą	    Š	  "  ą	  $  š	     
      «(½Y          
  
    
     0
     @
     P
     `
     p
     
  '   
     
    °
    Ą
  	  Š
    ą
    š
                  0    @    P    `  "  p  $            «(½Y          h     «(½Y       	         «(½Y             «(½Y           °      «(½Y          Č     «(½Y       	  Ą   R E G I N S T  R E G I N S T  W I N E _ R E G I S T R Y 	 B L A N K . H T M Š  į3          “?  +          Šj  Ö           Øk  ą           l  Ņ           \m  Ņ           0n  Ö           o  Ō           Üo  ę           Äp  Ī           q  Š           dr  ą           Ds  Š           t  Č           Üt  Ō           °u  Š           v  Š           Pw  Ö           (x  Ī           ųx  Ī           Čy  Č           z  Š           `{  Š           0|  Ö           }  Ö           ą}  Ü           ¼~  Č                                   “            L            ä              ²          4            ¼  |          8            Ä            L  \          Ø            @            Č            P  j          ¼            \  n          Ģ  d          0            “            D            Ä  v          <”            Ų¢  ¤          |¤  \          Ų„            p§  :           ¬§  <           č§  :           $Ø  <           `Ø  :           Ø  :           ŲØ  :           ©  :           P©  >           ©  :           Ģ©  .           ü©  :           8Ŗ  :           tŖ  >           “Ŗ  2           čŖ  >           («  .           X«  .           «  :           Ä«  <            ¬  :           <¬  8           t¬  :           °¬  :           ģ¬  .           ­  Z           x­  T           Ģ­  T            ®  T           t®  T           Č®  p           8Æ  N           Æ  T           ÜÆ  T           0°  T           °  8           ¼°  T           ±  T           d±  T           ø±  T           ²  T           `²  T           “²  T           ³  P           X³  T           ¬³  P           ü³  b           `“  T           ““  T           µ  8           @µ  l          ¬¹             ¼¹  ķ          [version]
Signature="$CHICAGO$"


[RegisterDll]
AddReg=Classes.Reg, Protocols.Reg, IE.Reg, FileAssoc.Reg


[UnregisterDll]
DelReg=Classes.Reg, Protocols.Reg, IE.Reg


[Classes.Reg]

;; CrSource
HKCR,"CLSID\%CLSID_CrSource%\BrowseInPlace",,16
;;HKCR,"CLSID\%CLSID_CrSource%\DefaultIcon",,0x00020000,"%16422%\Internet Explorer\iexplore.exe,1"
HKCR,"CLSID\%CLSID_CrSource%\EnablePlugin\.css",,,"PointPlus plugin"
HKCR,"CLSID\%CLSID_CrSource%\MiscStatus",,,"2228625"

;; HTADocument
HKCR,"CLSID\%CLSID_HTADocument%\BrowseInPlace",,16
HKCR,"CLSID\%CLSID_HTADocument%\MiscStatus",,,"2228625"

;; HTMLDocument
HKCR,"CLSID\%CLSID_HTMLDocument%\BrowseInPlace",,16
;;HKCR,"CLSID\%CLSID_HTMLDocument%\DefaultIcon",,0x00020000,"%16422%\Internet Explorer\iexplore.exe,1"
HKCR,"CLSID\%CLSID_HTMLDocument%\MiscStatus",,,"2228625"
HKCR,"CLSID\%CLSID_HTMLDocument%\EnablePlugin\.css",,,"PointPlus plugin"

;; HTMLPluginDocument
HKCR,"CLSID\%CLSID_HTMLPluginDocument%\BrowseInPlace",,16
HKCR,"CLSID\%CLSID_HTMLPluginDocument%\MiscStatus",,,"0"

;; IImageDecodeFilter
HKCR,"MIME\Database\Content Type\image/x-wmf","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,"MIME\Database\Content Type\image/x-wmf\Bits","0",1,04,00,00,00,FF,FF,FF,FF,D7,CD,C6,9A

;; MHTMLDocument
HKCR,"CLSID\%CLSID_MHTMLDocument%\BrowseInPlace",,16
;;HKCR,"CLSID\%CLSID_MHTMLDocument%\DefaultIcon",,0x00020000,"%16422%\Internet Explorer\iexplore.exe,1"
HKCR,"CLSID\%CLSID_MHTMLDocument%\MiscStatus",,,"2228625"

;; Scriptlet
HKCR,"CLSID\%CLSID_Scriptlet%\Control",,16
HKCR,"CLSID\%CLSID_Scriptlet%\MiscStatus",,,"0"
HKCR,"CLSID\%CLSID_Scriptlet%\MiscStatus\1",,,"131473"
HKCR,"CLSID\%CLSID_Scriptlet%\Programmable",,16
;;HKCR,"CLSID\%CLSID_Scriptlet%\ToolboxBitmap32",,,"%16422%\Internet Explorer\iexplore.exe,1"
HKCR,"MIME\Database\Content Type\text/x-scriptlet","CLSID",,"%CLSID_Scriptlet%"


[Protocols.Reg]
HKCR,"PROTOCOLS\Handler\javascript","CLSID",,"%CLSID_JSProtocol%"
HKCR,"PROTOCOLS\Handler\vbscript","CLSID",,"%CLSID_JSProtocol%"
HKCR,"PROTOCOLS\Handler\about","CLSID",,"%CLSID_AboutProtocol%"
HKCR,"PROTOCOLS\Handler\res","CLSID",,"%CLSID_ResProtocol%"
HKCR,"PROTOCOLS\Handler\mailto","CLSID",,"%CLSID_MailtoProtocol%"
HKCR,"PROTOCOLS\Handler\sysimage","CLSID",,"%CLSID_SysImageProtocol%"


[IE.Reg]
HKLM,"Software\Microsoft\Internet Explorer\Version Vector", "IE",,"6.0000"
HKLM,"Software\Microsoft\Internet Explorer\AboutURLs","blank",2,"res://mshtml.dll/blank.htm"
HKLM,"Software\Microsoft\Internet Explorer\AboutURLs","PostNotCached",2,"res://mshtml.dll/repost.htm"
HKLM,"Software\Microsoft\Internet Explorer\AboutURLs","mozilla",2,"res://mshtml.dll/about.moz"
HKLM,"Software\Microsoft\Internet Explorer\Default Behaviors","VML",,  "CLSID:10072CEC-8CC1-11D1-986E-00A0C955B42E"
HKLM,"Software\Microsoft\Internet Explorer\Default Behaviors","TIME",, "CLSID:476C391C-3E0D-11D2-B948-00C04FA32195"
HKLM,"Software\Microsoft\Internet Explorer\ActiveX Compatibility","Version",,"6.17"


[FileAssoc.Reg]

;; AVI
HKCR,"MIME\Database\Content Type\video/avi","CLSID",,"{CD3AFA88-B84F-48F0-9393-7EDC34128127}"
HKCR,"MIME\Database\Content Type\video/avi","Extension",,".avi"
HKCR,".avi","Content Type",,"video/avi"

;; BMP
HKCR,"MIME\Database\Content Type\image/bmp","Extension",,".bmp"
HKCR,"MIME\Database\Content Type\image/bmp","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,"MIME\Database\Content Type\image/bmp\Bits","0",1,02,00,00,00,FF,FF,42,4D
HKCR,".bmp","Content Type",,"image/bmp"

;; CSS
HKCR,"MIME\Database\Content Type\text/css","Extension",,".css"
HKCR,".css","Content Type",,"text/css"

;; DIB
HKCR,".dib","Content Type",,"image/bmp"

;; DLL
HKCR,".dll","Content Type",,"application/x-msdownload"
HKCR,".dll",,,"dllfile"

;; EXE
HKCR,".exe","Content Type",,"application/x-msdownload"
HKCR,".exe",,,"exefile"

;; GIF
HKCR,"MIME\Database\Content Type\image/gif","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\image/gif","Extension",,".gif"
HKCR,"MIME\Database\Content Type\image/gif","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,"MIME\Database\Content Type\image/gif\Bits","0",1,04,00,00,00,FF,FF,FF,FF,47,49,46,38
HKCR,".gif",,2,"giffile"
HKCR,".gif","Content Type",,"image/gif"
HKCR,"giffile",,,"GIF Image"
HKCR,"giffile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"giffile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"giffile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"giffile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"giffile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"giffile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,9"

;; GZIP
HKCR,"MIME\Database\Content Type\application/x-gzip","Extension",,".gz"
HKCR,".gz","Content Type",,"application/x-gzip"

;; HTC
HKCR,"MIME\Database\Content Type\text/x-component","CLSID",,"%CLSID_CHtmlComponentConstructor%"
HKCR,"MIME\Database\Content Type\text/x-component","Extension",,".htc"
HKCR,".htc","Content Type",,"text/x-component"

;; HTML
HKCR,"MIME\Database\Content Type\text/html","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\text/html","Extension",,".htm"
HKCR,"MIME\Database\Content Type\text/html","Encoding",1,08,00,00,00
HKCR,"MIME\Database\Content Type\image/x-jg","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"InternetShortcut\shell\print\command",,,"rundll32.exe mshtml.dll,PrintHTML ""%%1"""
HKCR,"InternetShortcut\shell\printto\command",,,"rundll32.exe mshtml.dll,PrintHTML ""%%1"" ""%%2"" ""%%3"" ""%%4"""
HKCR,"htmlfile\shell\print\command",,,"rundll32.exe mshtml.dll,PrintHTML ""%%1"""
HKCR,"htmlfile\shell\printto\command",,,"rundll32.exe mshtml.dll,PrintHTML ""%%1"" ""%%2"" ""%%3"" ""%%4"""
HKCR,"htmlfile",,,"HTML Document"
HKCR,"htmlfile\BrowseInPlace",,16
HKCR,"htmlfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"htmlfile\DefaultIcon",,0x00020000,"%16422%\Internet Explorer\iexplore.exe,1"
HKCR,"htmlfile_FullWindowEmbed",,,"HTML Plugin Document"
HKCR,"htmlfile_FullWindowEmbed\BrowseInPlace",,16
HKCR,"htmlfile_FullWindowEmbed\CLSID",,,"%CLSID_HTMLPluginDocument%"
HKCR,".htm",,,"htmlfile"
HKCR,".htm","Content Type",,"text/html"
HKCR,".html",,,"htmlfile"
HKCR,".html","Content Type",,"text/html"

;; ICO
HKCR,"MIME\Database\Content Type\image/x-icon","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\image/x-icon","Extension",,".ico"
HKCR,"MIME\Database\Content Type\image/x-icon","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,".ico","Content Type",,"image/x-icon"

;; JPE
HKCR,".jpe",,2,"jpegfile"
HKCR,".jpe","Content Type",,"image/jpeg"
HKCR,"jpegfile",,,"JPEG Image"
HKCR,"jpegfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"jpegfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"jpegfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"jpegfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"jpegfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"jpegfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,8"

;; JPEG
HKCR,"MIME\Database\Content Type\image/jpeg","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\image/jpeg","Extension",,".jpg"
HKCR,"MIME\Database\Content Type\image/jpeg\Bits","0",1,02,00,00,00,FF,FF,FF,D8
HKCR,"MIME\Database\Content Type\image/jpeg","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,".jpeg",,2,"jpegfile"
HKCR,".jpeg","Content Type",,"image/jpeg"
HKCR,"jpegfile",,,"JPEG Image"
HKCR,"jpegfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"jpegfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"jpegfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"jpegfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"jpegfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"jpegfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,8"

;; JPG
HKCR,".jpg",,2,"jpegfile"
HKCR,".jpg","Content Type",,"image/jpeg"
HKCR,"jpegfile",,,"JPEG Image"
HKCR,"jpegfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"jpegfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"jpegfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"jpegfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"jpegfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"jpegfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,8"

;; MHTML
HKCR,"MIME\Database\Content Type\message/rfc822","CLSID",,"%CLSID_MHTMLDocument%"
HKCR,".mhtml",,2,"mhtmlfile"
HKCR,".mhtml","Content Type",,"message/rfc822"
HKCR,".mht",,2,"mhtmlfile"
HKCR,".mht","Content Type",,"message/rfc822"
HKCR,"mhtmlfile",,,"MHTML Document"
HKCR,"mhtmlfile\BrowseInPlace",,16
HKCR,"mhtmlfile\CLSID",,,"%CLSID_MHTMLDocument%"

;; MPEG
HKCR,"MIME\Database\Content Type\audio/mpeg","CLSID",,"{CD3AFA76-B84F-48F0-9393-7EDC34128127}"
HKCR,"MIME\Database\Content Type\audio/mpeg","Extension",,".mp3"
HKCR,"MIME\Database\Content Type\audio/mpg","CLSID",,"{CD3AFA76-B84F-48F0-9393-7EDC34128127}"
HKCR,"MIME\Database\Content Type\audio/mpg","Extension",,".mp3"
HKCR,"MIME\Database\Content Type\video/mpeg","CLSID",,"{CD3AFA89-B84F-48F0-9393-7EDC34128127}"
HKCR,"MIME\Database\Content Type\video/mpeg","Extension",,".mpeg"
HKCR,".mp3","Content Type",,"audio/mpeg"
HKCR,".mpe","Content Type",,"video/mpeg"
HKCR,".mpeg","Content Type",,"video/mpeg"
HKCR,".mpg","Content Type",,"video/mpeg"

;; PJPG
HKCR,"MIME\Database\Content Type\image/pjpeg","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\image/pjpeg","Extension",,".jpg"
HKCR,"MIME\Database\Content Type\image/pjpeg\Bits","0",1,02,00,00,00,FF,FF,FF,D8
HKCR,"MIME\Database\Content Type\image/pjpeg","Image Filter CLSID",,"%CLSID_IImageDecodeFilter%"
HKCR,".jfif",,2,"pjpegfile"
HKCR,".jfif","Content Type",,"image/jpeg"
HKCR,"pjpegfile",,,"JPEG Image"
HKCR,"pjpegfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"pjpegfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"pjpegfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"pjpegfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"pjpegfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"pjpegfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,8"

;; PNG
HKCR,"MIME\Database\Content Type\image/png","Extension",,".png"
HKCR,"MIME\Database\Content Type\image/x-png","Extension",,".png"
HKCR,".png",,2,"pngfile"
HKCR,".png","Content Type",,"image/png"
HKCR,"pngfile",,,"PNG Image"
HKCR,"pngfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"pngfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe""" -nohome"
HKCR,"pngfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"pngfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"pngfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"pngfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,9"

;; PS
HKCR,"MIME\Database\Content Type\application/postscript","Extension",,".ps"
HKCR,".ai","Content Type",,"application/postscript"
HKCR,".eps","Content Type",,"application/postscript"
HKCR,".ps","Content Type",,"application/postscript"

;; TAR
HKCR,"MIME\Database\Content Type\application/x-tar","Extension",,".tar"
HKCR,".tar","Content Type",,"application/x-tar"

;; TGZ
HKCR,"MIME\Database\Content Type\application/x-compressed","Extension",,".tgz"
HKCR,".tgz","Content Type",,"application/x-compressed"

;; TIFF
HKCR,"MIME\Database\Content Type\image/tiff","Extension",,".tiff"
HKCR,".tif","Content Type",,"image/tiff"
HKCR,".tiff","Content Type",,"image/tiff"

;; TXT
HKCR,"MIME\Database\Content Type\text/plain","CLSID",,"%CLSID_HTMLDocument%"
HKCR,"MIME\Database\Content Type\text/plain","Extension",,".txt"
HKCR,"MIME\Database\Content Type\text/plain","Encoding",1,07,00,00,00
HKCR,".txt",,,"txtfile"
HKCR,".txt","Content Type",,"text/plain"

;; WAV
HKCR,"MIME\Database\Content Type\audio/wav","CLSID",,"{CD3AFA7B-B84F-48F0-9393-7EDC34128127}"
HKCR,"MIME\Database\Content Type\audio/wav","Extension",,".wav"
HKCR,".wav","Content Type",,"audio/wav"

;; XBM
HKCR,"MIME\Database\Content Type\image/xbm","Extension",,".xbm"
HKCR,"MIME\Database\Content Type\image/x-xbitmap","CLSID",,"%CLSID_HTMLDocument%"
HKCR,".xbm","Content Type",,"image/x-xbitmap"
HKCR,"xbmfile",,,"XBM Image"
HKCR,"xbmfile\CLSID",,,"%CLSID_HTMLDocument%"
;;HKCR,"xbmfile\shell\open\command",,,"""%16422%\Internet Explorer\iexplore.exe"" -nohome"
HKCR,"xbmfile\shell\open\ddeexec",,,"""file:%%1"",,-1,,,,,"
;;HKCR,"xbmfile\shell\open\ddeexec\Application",,,"IExplore"
HKCR,"xbmfile\shell\open\ddeexec\Topic",,,"WWW_OpenURL"
;; HKCR,"xbmfile\DefaultIcon",,,"%16422%\Internet Explorer\iexplore.exe,9"

;; XML
HKCR,"MIME\Database\Content Type\application/xml","CLSID",,"{48123BC4-99D9-11D1-A6B3-00C04FD91555}"
HKCR,"MIME\Database\Content Type\application/xml","Extension",,".xml"
HKCR,"MIME\Database\Content Type\application/xml","Encoding",1,08,00,00,00
HKCR,"MIME\Database\Content Type\text/xml","CLSID",,"{48123BC4-99D9-11D1-A6B3-00C04FD91555}"
HKCR,"MIME\Database\Content Type\text/xml","Extension",,".xml"
HKCR,"MIME\Database\Content Type\text/xml","Encoding",1,08,00,00,00
HKCR,".xml",,,"xmlfile"
HKCR,".xml","Content Type",,"text/xml"
HKCR,".xsl",,,"xslfile"
HKCR,".xsl","Content Type",,"text/xml"

;; ZIP
HKCR,"MIME\Database\Content Type\application/x-zip-compressed","Extension",,".zip"
HKCR,".zip","Content Type",,"application/x-zip-compressed"
   HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{3050F406-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML About Pluggable Protocol'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3BB-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Anchor Element Browse Property Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F232-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Background Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F1FC-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Anchor Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F17F-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Generic Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3B4-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Document Browse Property Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3C2-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML DwnBindInfo'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F163-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML External Document'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{5AAF51B3-B1F0-11D1-B6AB-00A0C90833E9}' = s 'Microsoft Scriptlet HiFiTimer Uses'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'Scriptlet.HiFiTimer'
        }
        '{3050F4F8-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Html Component'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3B3-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Image Element Browse Property Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F296-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Inline Style Page'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{5AAF51B2-B1F0-11D1-B6AB-00A0C90833E9}' = s 'Microsoft Scriptlet Element Behavior Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'Scriptlet.Behavior'
        }
        '{3050F499-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Recalc'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{65014010-9F62-11D1-A651-00600811D5CE}' = s 'Microsoft CrSource 4.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'CrSource'
            Version = s '4.0'
        }
        '{3050F4F0-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Scriptlet svr om Uses'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'Scriptlet.SvrOm'
        }
        '{3050F5C8-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTA Document 6.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            Version = s '6.0'
        }
        '{25336920-03F9-11CF-8FD0-00AA00686F13}' = s 'HTML Document'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'htmlfile'
            Version = s '6.0'
        }
        '{25336921-03F9-11CF-8FD0-00AA00686F13}' = s 'Microsoft HTML Document 6.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'htmlfile_FullWindowEmbed'
        }
        '{3050F667-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Html Popup Window'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F67D-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft Html Document for Popup Window'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F4E7-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Server Document 6.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F391-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Window Security Proxy'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}' = s 'CoBMPFilter Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'BMPFilter.CoBMPFilter.1'
            VersionIndependentProgId = s 'BMPFilter.CoBMPFilter'
        }
        '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}' = s 'CoGIFFilter Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'GIFFilter.CoGIFFilter.1'
            VersionIndependentProgId = s 'GIFFilter.CoGIFFilter'
        }
        '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}' = s 'CoJPEGFilter Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'JPEGFilter.CoJPEGFilter.1'
            VersionIndependentProgId = s 'JPEGFilter.CoJPEGFilter'
        }
        '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}' = s 'CoWMFFilter Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'WMFFilter.CoWMFFilter.1'
            VersionIndependentProgId = s 'WMFFilter.CoWMFFilter'
        }
        '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}' = s 'CoICOFilter Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'ICOFilter.CoICOFilter.1'
            VersionIndependentProgId = s 'ICOFilter.CoICOFilter'
        }
        '{3050F3D6-98B5-11CF-BB82-00AA00BDCE0B}' = s 'IImgCtx'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'IImgCtx'
        }
        '{18845040-0FA5-11D1-BA19-00C04FD912D0}' = s 'Microsoft HTML Load Options'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{05F6FE1A-ECEF-11D0-AAE7-00C04FC9B304}' = s 'IntDitherer Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3B2-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Javascript Pluggable Protocol'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3DA-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Mailto Pluggable Protocol'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3050F3D9-98B5-11CF-BB82-00AA00BDCE0B}' = s 'MHTML Document'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'mhtmlfile'
            Version = s '6.0'
        }
        '{3050F3BC-98B5-11CF-BB82-00AA00BDCE0B}' = s 'Microsoft HTML Resource Pluggable Protocol'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{AE24FDAE-03C6-11D1-8B76-0080C744F389}' = s 'Microsoft Scriptlet Component'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'ScriptBridge.ScriptBridge.1'
            VersionIndependentProgId = s 'ScriptBridge.ScriptBridge'
        }
        '{76E67A63-06E9-11D2-A840-006008059382}' = s 'Microsoft HTML Resource Pluggable Protocol'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{429AF92C-A51F-11D2-861E-00C04FA35C89}' = s 'Trident API'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
    'Scriptlet.HiFiTimer' = s 'Microsoft Scriptlet HiFiTimer Uses'
    {
        CLSID = s '{5AAF51B3-B1F0-11D1-B6AB-00A0C90833E9}'
    }
    'Scriptlet.Behavior' = s 'Microsoft Scriptlet Element Behavior Handler'
    {
        CLSID = s '{5AAF51B2-B1F0-11D1-B6AB-00A0C90833E9}'
    }
    'CrSource' = s 'Microsoft CrSource 4.0'
    {
        CLSID = s '{65014010-9F62-11D1-A651-00600811D5CE}'
    }
    'Scriptlet.SvrOm' = s 'Microsoft Scriptlet svr om Uses'
    {
        CLSID = s '{3050F4F0-98B5-11CF-BB82-00AA00BDCE0B}'
    }
    'htmlfile' = s 'HTML Document'
    {
        CLSID = s '{25336920-03F9-11CF-8FD0-00AA00686F13}'
    }
    'htmlfile_FullWindowEmbed' = s 'Microsoft HTML Document 6.0'
    {
        CLSID = s '{25336921-03F9-11CF-8FD0-00AA00686F13}'
    }
    'BMPFilter.CoBMPFilter.1' = s 'CoBMPFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
    }
    'BMPFilter.CoBMPFilter' = s 'CoBMPFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
        CurVer = s 'BMPFilter.CoBMPFilter.1'
    }
    'GIFFilter.CoGIFFilter.1' = s 'CoGIFFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
    }
    'GIFFilter.CoGIFFilter' = s 'CoGIFFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
        CurVer = s 'GIFFilter.CoGIFFilter.1'
    }
    'JPEGFilter.CoJPEGFilter.1' = s 'CoJPEGFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
    }
    'JPEGFilter.CoJPEGFilter' = s 'CoJPEGFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
        CurVer = s 'JPEGFilter.CoJPEGFilter.1'
    }
    'WMFFilter.CoWMFFilter.1' = s 'CoWMFFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
    }
    'WMFFilter.CoWMFFilter' = s 'CoWMFFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
        CurVer = s 'WMFFilter.CoWMFFilter.1'
    }
    'ICOFilter.CoICOFilter.1' = s 'CoICOFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
    }
    'ICOFilter.CoICOFilter' = s 'CoICOFilter Class'
    {
        CLSID = s '{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}'
        CurVer = s 'ICOFilter.CoICOFilter.1'
    }
    'IImgCtx' = s 'IImgCtx'
    {
        CLSID = s '{3050F3D6-98B5-11CF-BB82-00AA00BDCE0B}'
    }
    'mhtmlfile' = s 'MHTML Document'
    {
        CLSID = s '{3050F3D9-98B5-11CF-BB82-00AA00BDCE0B}'
    }
    'ScriptBridge.ScriptBridge.1' = s 'Microsoft Scriptlet Component'
    {
        CLSID = s '{AE24FDAE-03C6-11D1-8B76-0080C744F389}'
    }
    'ScriptBridge.ScriptBridge' = s 'Microsoft Scriptlet Component'
    {
        CLSID = s '{AE24FDAE-03C6-11D1-8B76-0080C744F389}'
        CurVer = s 'ScriptBridge.ScriptBridge.1'
    }
}
    ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A b b r e c h e n        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ A c e p t a r                 Pn A 2     ’’ C a n c e l a r      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n n u l e r        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n n u l l a        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n n u l e r e n        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ C a n c e l a r      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ C o n & f i r m                 Pn A 2     ’’ A & n u l e a z        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n u l o        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A v b r y t      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ G e r a i                 Pn A 2     ’’ A t s i s a k y t i      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ C a n c e l      ’’        H Č     Č Z       	    M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ ŗx[              Pn A 2     ’’ ÖSm     ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n n u l l e r      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ C a n c e l      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ C a n c e l      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ ŠŁéÕč                Pn A 2     ’’ ŃŁŲÕÜ       ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ M é g s e        ’’        H Č     Č Z       	    M S   U I   G o t h i c             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ ­0ć0ó0»0ė0       ’’        H Č     Č Z       	    M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ UÖxĒ              Pn A 2     ’’ čĶĮ     ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ A n u l u j      ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ B<5=0     ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ T a m a m                 Pn A 2     ’’ 0p t a l        ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ O K               Pn A 2     ’’ !:0AC20B8       ’’        H Č     Č Z           M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ V   r e d u               Pn A 2     ’’ P r e k l i i      ’’        H Č     Č Z       	    M S   S h e l l   D l g             P
 
 “    ’’              P
 - “    ’’              P( A 2     ’’ nx[              Pn A 2     ’’ ÖSm     ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H y p e r l i n k - E i g e n s c h a f t e n                 P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A b b r e c h e n        ’’        HČ     ’ A     E n l a c e       M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ I n f o r m a c i ó n   s o b r e   e l   e n l a c e                 P
   
 ’’’’’’ & T i p o   :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ A c e p t a r                 PČ  2     ’’ A n u l a r      ’’        HČ     ’ A     H y p e r l i e n       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ I n f o r m a t i o n s   s u r   l ' h y p e r l i e n               P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n n u l e r        ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ I n f o r m a z i o n i   s u l l ' h y p e r l i n k                 P
   
 ’’’’’’ & T i p o :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n n u l l a        ’’        HČ     ’ A     W e b v e r w i j z i n g       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ W e b v e r w i j z i n g   I n f o r m a t i e               P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n n u l e r e n        ’’        HČ     ’ A     H i p e r l e g t u r       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ I n f o r m a i i   d e   h i p e r l e g t u r                 P
   
 ’’’’’’ & T i p :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ C o n & f i r m                 PČ  2     ’’ A & n u l e a z        ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H y p e r l i n k   I n f o r m a c i o n i               P
   
 ’’’’’’ & T i p i :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n u l o        ’’        HČ     ’ A     H y p e r l ä n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ L ä n k i n f o r m a t i o n                 P
   
 ’’’’’’ & T y p :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A v b r y t      ’’        HČ     ’ A     S a i t a s       M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ S a i t o   i n f o r m a c i j a                 P
   
 ’’’’’’ & T i p a s :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ G e r a i                 PČ  2     ’’ A t s i s a k y t i      ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H y p e r l i n k   I n f o r m a t i o n                 P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ C a n c e l      ’’        HČ     ’ A     Č„c  	    M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ Č„cĒ
                P
   
 ’’’’’’ ^W( & T ) :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ ²}@W( & U ) :                P# (   )#  ’’              PČ 
 2     ’’ ŗx[              PČ  2     ’’ ÖSm     ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ I n f o r m a t i o n   o m   H y p e r l i n k ' e n                 P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n n u l l e r      ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H y p e r l i n k   I n f o r m a t i o n                 P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ C a n c e l      ’’        HČ     ’ A     H y p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H y p e r l i n k   I n f o r m a t i o n                 P
   
 ’’’’’’ & T y p e :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ C a n c e l      ’’        HČ     ’ A     ēŁéÕč      M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ ŽŁÓā  ēŁéÕč              P
   
 ’’’’’’ įÕŅ:             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ ŠŁéÕč                PČ  2     ’’ ŃŁŲÕÜ       ’’        HČ     ’ A     H i p e r h i v a t k o z į s       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ H i p e r h i v a t k o z į s   i n f o r m į c i ó               P
   
 ’’’’’’ & T ķ p u s :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ M é g s e        ’’        HČ     ’ A     Ļ0¤0Ń0ü0ź0ó0Æ0  	    M S   U I   G o t h i c               P  ¾ 7 ’’’’’’ Ļ0¤0Ń0ü0ź0ó0Æ0n0Å`1X              P
   
 ’’’’’’ .z^( & T ) :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ ­0ć0ó0»0ė0       ’’        HČ     ’ A     XÕtĒ|ÓĮ¹lŠ  	    M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ XÕtĒ|ÓĮ¹lŠ  Čō¼              P
   
 ’’’’’’ ÖŻĀ( & T ) :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ üČĮ( & U ) :                P# (   )#  ’’              PČ 
 2     ’’ UÖxĒ              PČ  2     ’’ čĶĮ     ’’        HČ     ’ A     H i p e r Bc z e       M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ W Ba s n o [c i   h i p e r Bc z a               P
   
 ’’’’’’ & T y p :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ A n u l u j      ’’        HČ     ’ A     H i p e r l i n k       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ I n f o r m a ē ć o   d o   H i p e r l i n k                 P
   
 ’’’’’’ & T i p o :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ C a n c e l a r      ’’        HČ     ’ A     !AK;:0      M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ =D>@<0F8O  >  AAK;:5                P
   
 ’’’’’’ & "8?:               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & 4@5A:                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ B<5=0     ’’        HČ     ’ A     K ö p r ü       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ K ö p r ü   B i l g i s i                 P
   
 ’’’’’’ & T ü r :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ T a m a m                 PČ  2     ’’ 0p t a l        ’’        HČ     ’ A     V?5@?>A8;0==O      M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ 0=V  ?@>  V?5@?>A8;0==O                P
   
 ’’’’’’ & "8?:               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ !:0AC20B8       ’’        HČ     ’ A     H i p e r p o v e z a v a       M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ L a s t n o s t i   h i p e r p o v e z a v e                 P
   
 ’’’’’’ & V r s t a :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ V   r e d u               PČ  2     ’’ P r e k l i i      ’’        HČ     ’ A     ž„c  	    M S   S h e l l   D l g               P  ¾ 7 ’’’’’’ ž„cįOo`                P
   
 ’’’’’’ {|W( & T ) :               #P#  - d *#  ’’               P
 *  
 ’’’’’’ Q@W( & U ) :                P# (   )#  ’’              PČ 
 2     ’’ nx[              PČ  2     ’’ ÖSm     ’’        HČ     ’ A     H i p e r l i g a ē ć o       M S   S h e l l   D l g             P  ¾ 7 ’’’’’’ I n f o r m a ē ć o   d a   H i p e r l i g a ē ć o               P
   
 ’’’’’’ & T i p o :             #P#  - d *#  ’’               P
 *  
 ’’’’’’ & U R L :                P# (   )#  ’’              PČ 
 2     ’’ O K               PČ  2     ’’ C a n c e l a r                                H T M L - D o k u m e n t                                  D o c u m e n t o   H T M L                                D o c u m e n t   H T M L                                  D o c u m e n t o   H T M L                                H T M L   d o c u m e n t                                  D o c u m e n t   H T M L                                  H T M L   D o c u m e n t                                  H T M L - d o k u m e n t                                  H T M L   d o k u m e n t a s                                  H T M L   D o c u m e n t                                  H T M L   jHh                                 H T M L   d o k u m e n t                                  H T M L   D o c u m e n t                                  H T M L   D o k u m e n t t i                                 	 ŽįŽŚ  H T M L                                  H T M L   d o k u m e n t u m                                  H T M L   eųf                                 H T M L   8»Į                                 D o k u m e n t   H T M L                                  D o c u m e n t o   H T M L                                >:C<5=B  H T M L                                  H T M L   B e l g e s i                                >:C<5=B  H T M L                                  H T M L   d o k u m e n t                                  H T M L   eöN                                   H e r u n t e r l a d e n   v o n   % s . . .  F e r t i g                                D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              Ī n   c u r s   d e   d e s c r c a r e   d e   l a   % s & 	 F i n a l i z a t                              S h k a r k o   n g a   % s . . .  e   B ė r ė                                D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                             
 _  % s N	-N. . .  [bu                             D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              P o b i e r a n i e   z   % s . . .  G o t o w e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                              !:0G820=85  A  % s . . .  >B>2>                             % s   a d r e s i n d e n   i n d i r i l i y o r . . .  T a m a m                                D o w n l o a d i n g   f r o m   % s . . .  D o n e                              D o w n l o a d i n g   f r o m   % s . . .  D o n e                             
 ĪN  % s N}-N. . .  [bl4   V S _ V E R S I O N _ I N F O     ½ļž      Rš
      ?                        Ģ   S t r i n g F i l e I n f o   Ø   0 4 0 9 0 4 b 0   f #  C o m p a n y N a m e     R e a c t O S   D e v e l o p m e n t   T e a m / W i n e   T e a m     J   F i l e D e s c r i p t i o n     W i n e   H T M L   V i e w e r     <   F i l e V e r s i o n     6 . 0 . 2 8 0 0 . 1 1 0 6   6   I n t e r n a l N a m e   m s h t m l . d l l     ä \  O r i g i n a l C o p y r i g h t     C o p y r i g h t   ( c )   1 9 9 3 - 2 0 1 7   t h e   W i n e   p r o j e c t   a u t h o r s   ( s e e   t h e   f i l e   A U T H O R S   f o r   a   c o m p l e t e   l i s t )   ® E  L e g a l C o p y r i g h t   C o p y r i g h t   1 9 9 8 - 2 0 1 7   R e a c t O S   T e a m ,   1 9 9 3 - 2 0 1 7   t h e   W i n e   p r o j e c t   a u t h o r s     >   O r i g i n a l F i l e n a m e   m s h t m l . d l l     R   P r o d u c t N a m e     R e a c t O S   O p e r a t i n g   S y s t e m     @   P r o d u c t V e r s i o n   6 . 0 . 2 8 0 0 . 1 1 0 6   D    V a r F i l e I n f o     $    T r a n s l a t i o n     	°<HTML></HTML>
  <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
<dependency>
    <dependentAssembly>
        <assemblyIdentity
            type="win32"
            name="Microsoft.Windows.Common-Controls"
            version="6.0.0.0"
            publicKeyToken="6595b64144ccf1df"
            processorArchitecture="*"
            language="*"
        />
    </dependentAssembly>
</dependency>
<trustInfo xmlns="urn:schemas-microsoft-com:asm.v3">
    <security>
        <requestedPrivileges>
            <requestedExecutionLevel
                level="asInvoker"
                uiAccess="false"
            />
        </requestedPrivileges>
    </security>
</trustInfo>
</assembly>
   0       @       P       `       p                             °       Ą       Š       ą       š                              0       @       P       `       p                             °       Ą       Š       ą       š                              0       @       P       `       p                             °       Ą       Š       ą       š                              0       @       P       `       p                             °       Ą       Š       ą       š        	       	        	       0	       @	       P	       `	       p	       	       	        	       °	       Ą	       Š	       ą	       š	        
       
        
       0
       @
       P
       `
       p
       
       
        
       °
       Ą
       Š
       ą
       š
                              0       @       P       `       p                             °       Ą       .rsrc              