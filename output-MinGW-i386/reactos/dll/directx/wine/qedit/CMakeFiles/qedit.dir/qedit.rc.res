L     �       .rsrc           �  <   �         @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   3          HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{78530B75-61F9-11D2-8CAD-00A024580902}' = s 'AMTimeline'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{65BD0711-24D2-4FF7-9324-ED2E5D3ABAFA}' = s 'MediaDet'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{C1F400A0-3F08-11D3-9F0B-006008039E37}' = s 'Sample Grabber'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 d        .rsrc              