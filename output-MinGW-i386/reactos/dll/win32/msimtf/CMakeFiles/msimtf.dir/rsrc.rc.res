L            .rsrc           �  <            @ 0�    ���Y       H  �  �    ���Y          0  �    ���Y       	  d    W I N E _ R E G I S T R Y t   U          HKCR
{
    NoRemove Interface
    {
    }
    NoRemove CLSID
    {
        '{4955DD33-B159-11D0-8FCF-00AA006BCC59}' = s 'CActiveIMMApp'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{C1EE01F2-B3B6-4A6A-9DDD-E988C088EC82}' = s 'CActiveIMMAppEx'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{50D5107A-D278-4871-8989-F4CEAAF59CFC}' = s 'CActiveIMMAppEx_Trident'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
   d        .rsrc              