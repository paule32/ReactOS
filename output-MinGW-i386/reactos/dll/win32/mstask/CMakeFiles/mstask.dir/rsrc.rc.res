L     J       .rsrc             <   @         @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   �          HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{148BD52A-A2AB-11CE-B11F-00AA00530503}' = s 'CTaskScheduler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{148BD520-A2AB-11CE-B11F-00AA00530503}' = s 'CTask'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  d        .rsrc              