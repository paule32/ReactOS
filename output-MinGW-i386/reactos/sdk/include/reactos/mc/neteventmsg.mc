;  
 ;   n e t e v e n t . m c   M E S S A G E   r e s o u r c e s   f o r   n e t e v e n t . d l l  
 ;  
  
 M e s s a g e I d T y p e d e f = D W O R D  
  
 S e v e r i t y N a m e s = ( S u c c e s s = 0 x 0 : S T A T U S _ S E V E R I T Y _ S U C C E S S  
                               I n f o r m a t i o n a l = 0 x 1 : S T A T U S _ S E V E R I T Y _ I N F O R M A T I O N A L  
                               W a r n i n g = 0 x 2 : S T A T U S _ S E V E R I T Y _ W A R N I N G  
                               E r r o r = 0 x 3 : S T A T U S _ S E V E R I T Y _ E R R O R  
                             )  
  
 F a c i l i t y N a m e s = ( S y s t e m = 0 x 0 : F A C I L I T Y _ S Y S T E M  
                             )  
  
 L a n g u a g e N a m e s = ( E n g l i s h = 0 x 4 0 9 : M S G 0 0 4 0 9  
                               R u s s i a n = 0 x 4 1 9 : M S G 0 0 4 1 9 )  
  
  
 ;  
 ;   m e s s a g e   d e f i n i t i o n s  
 ;  
  
 ;   F a c i l i t y = S y s t e m  
  
 ;  
 ;   e v e n t l o g   e v e n t s   6 0 0 0 - 6 0 9 9  
 ;  
  
 M e s s a g e I d = 6 0 0 0  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ L O G _ F U L L  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   l o g   f i l e   i s   f u l l .  
 .  
 L a n g u a g e = R u s s i a n  
 $09;  6C@=0;0  " % 1 "   70?>;=5=.  
 .  
  
 M e s s a g e I d = 6 0 0 1  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ L o g F i l e N o t O p e n e d  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   l o g   f i l e   c a n n o t   b e   o p e n e d .  
 .  
 L a n g u a g e = R u s s i a n  
 $09;  6C@=0;0  " % 1 "   =5  <>65B  1KBL  >B:@KB.  
 .  
  
 M e s s a g e I d = 6 0 0 2  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ L o g F i l e C o r r u p t  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   l o g   f i l e   i s   c o r r u p t e d   a n d   w i l l   b e   c l e a r e d .  
 .  
 L a n g u a g e = R u s s i a n  
 $09;  6C@0=0  " % 1 "   ?>2@5645=  8  1C45B  >G8I5=.  
 .  
  
 M e s s a g e I d = 6 0 0 3  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ D e f a u l t L o g C o r r u p t  
 L a n g u a g e = E n g l i s h  
 T h e   A p p l i c a t i o n   l o g   f i l e   c o u l d   n o t   b e   o p e n e d .     % 1   w i l l   b e   u s e d   a s   t h e   d e f a u l t   l o g   f i l e .  
 .  
 L a n g u a g e = R u s s i a n  
 $09;  6C@=0;0  " @8;>65=8O"   =5  <>65B  1KBL  >B:@KB.   " % 1 "   1C45B  8A?>;L7>20BLAO  2  :0G5AB25  D09;0  6C@0=0  ?>  C<>;G0=8N.  
 .  
  
 M e s s a g e I d = 6 0 0 4  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ B a d D r i v e r P a c k e t  
 L a n g u a g e = E n g l i s h  
 A   d r i v e r   p a c k e t   r e c e i v e d   f r o m   t h e   I / O   s u b s y s t e m   w a s   i n v a l i d .     T h e   d a t a   i s   t h e   p a c k e t .  
 .  
 L a n g u a g e = R u s s i a n  
 0:5B  4@0925@0,   ?>;CG5==K9  >B  ?>4A8AB5<K  22>40- 2K2>40  =54>?CAB8<.   0==K5  O2;ONBAO  ?0:5B><.  
 .  
  
 M e s s a g e I d = 6 0 0 5  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ E v e n t l o g S t a r t e d  
 L a n g u a g e = E n g l i s h  
 T h e   E v e n t   l o g   s e r v i c e   w a s   s t a r t e d .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  6C@0=0  A>1KB89  1K;0  70?CI5=0.  
 .  
  
 M e s s a g e I d = 6 0 0 6  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ E v e n t l o g S t o p p e d  
 L a n g u a g e = E n g l i s h  
 T h e   E v e n t   l o g   s e r v i c e   w a s   s t o p p e d .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  6C@=0;0  A>1KB89  1K;0  >AB0=>2;5=0.  
 .  
  
 M e s s a g e I d = 6 0 0 7  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = T I T L E _ E v e n t l o g M e s s a g e B o x  
 L a n g u a g e = E n g l i s h  
 E v e n t l o g   S e r v i c e   % 0  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  6C@=0;0  A>1KB89  % 0  
 .  
  
 M e s s a g e I d = 6 0 0 8  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ E v e n t l o g A b n o r m a l S h u t d o w n  
 L a n g u a g e = E n g l i s h  
 T h e   p r e v i o u s   s y s t e m   s h u t d o w n   a t   % 1   o n   % 2   w a s   u n e x p e c t e d .  
 .  
 L a n g u a g e = R u s s i a n  
 @54K4CI55  7025@H5=85  @01>BK  A8AB5<K  2  % 1   % 2   1K;>  =5>6840==K<.  
 .  
  
 M e s s a g e I d = 6 0 0 9  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ E v e n t L o g P r o d u c t I n f o  
 L a n g u a g e = E n g l i s h  
 R e a c t O S   % 1   % 2   % 3   % 4 .  
 .  
  
 M e s s a g e I d = 6 0 1 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S e r v i c e N o E v e n t L o g  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   w a s   u n a b l e   t o   s e t   u p   a n   e v e n t   s o u r c e .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   =5  A<>3;0  CAB0=>28BL  8AB>G=8:  A>1KB8O.  
 .  
  
 M e s s a g e I d = 6 0 1 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C o m p u t e r N a m e C h a n g e  
 L a n g u a g e = E n g l i s h  
 T h e   N e t B I O S   n a m e   a n d   D N S   h o s t   n a m e   o f   t h i s   m a c h i n e   h a v e   b e e n   c h a n g e d   f r o m   % 1   t o   % 2 .  
 .  
 L a n g u a g e = R u s s i a n  
 N e t B I O S   8  D N S   8<5=0  MB>3>  :><?LNB5@0  1K;8  87<5=5=K  A  " % 1 "   =0  " % 2 " .  
 .  
  
 M e s s a g e I d = 6 0 1 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ D N S D o m a i n N a m e C h a n g e  
 L a n g u a g e = E n g l i s h  
 T h e   D N S   d o m a i n   a s s i g n e d   t o   t h i s   c o m p u t e r   h a s   b e e n   c h a n g e d   f r o m   % 1   t o   % 2 .  
 .  
 L a n g u a g e = R u s s i a n  
 D N S - 4><5=  ?@8A2>5==K9  MB><C  :><?LNB5@C  1K;  87<5=5=  A  " % 1 "   =0  " % 2 " .  
 .  
  
  
 ;  
 ;   s y s t e m   e v e n t s   6 1 0 0   -   6 1 9 9  
 ;  
  
 M e s s a g e I d = 6 1 0 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ U P _ D R I V E R _ O N _ M P  
 L a n g u a g e = E n g l i s h  
 A   u n i p r o c e s s o r - s p e c i f i c   d r i v e r   w a s   l o a d e d   o n   a   m u l t i p r o c e s s o r   s y s t e m .     T h e   d r i v e r   c o u l d   n o t   l o a d .  
 .  
 L a n g u a g e = R u s s i a n  
 4=>?@>F5AA>@=K9  4@0925@  1K;  703@C65=  =0  <=>3>?@>F5AA>@=>9  A8AB5<5.   @0925@  =5  <>65B  1KBL  703@C65=.  
 .  
  
  
 ;  
 ;   s e r v i c e   c o n t r o l l e r   e v e n t s   7 0 0 0 - 7 8 9 9  
 ;  
  
 M e s s a g e I d = 7 0 0 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   f a i l e d   t o   s t a r t   d u e   t o   t h e   f o l l o w i n g   e r r o r :   % n % 2  
 .  
 L a n g u a g e = R u s s i a n  
 !;C615  " % 1 "   =5  C40;>AL  70?CAB8BLAO  87- 70  A;54CNI59  >H81:8:   % n % 2  
 .  
  
 M e s s a g e I d = 7 0 0 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ F A I L E D _ I I  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   d e p e n d s   o n   t h e   % 2   s e r v i c e   w h i c h   f a i l e d   t o   s t a r t   b e c a u s e   o f   t h e   f o l l o w i n g   e r r o r :   % n % 3  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   7028A8B  >B  A;C61K  " % 2 " ,   :>B>@>9  =5  C40;>AL  70?CAB8BLAO  87- 70  A;54CNI59  >H81:8:   % n % 3  
 .  
  
 M e s s a g e I d = 7 0 0 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ F A I L E D _ G R O U P  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   d e p e n d s   o n   t h e   % 2   g r o u p   a n d   n o   m e m b e r   o f   t h i s   g r o u p   s t a r t e d .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   7028A8B  >B  3@C??K  " % 2 "   8  =8  >48=  M;5<5=B  MB>9  3@C??K  =5  70?CI5=.  
 .  
  
 M e s s a g e I d = 7 0 0 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ F A I L E D _ N O N E  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   d e p e n d s   o n   t h e   f o l l o w i n g   n o n e x i s t e n t   s e r v i c e :   % 2  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   7028A8B  >B  A;54CNI59  =5ACI5AB2CNI59  A;C61K:   " % 2 "  
 .  
  
 M e s s a g e I d = 7 0 0 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C A L L _ T O _ F U N C T I O N _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   c a l l   f a i l e d   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 2  
 .  
 L a n g u a g e = R u s s i a n  
 K7>2  " % 1 "   7025@H8;AO  >H81:>9:   % n % 2  
 .  
  
 M e s s a g e I d = 7 0 0 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C A L L _ T O _ F U N C T I O N _ F A I L E D _ I I  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   c a l l   f a i l e d   f o r   % 2   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 3  
 .  
  
 M e s s a g e I d = 7 0 0 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ R E V E R T E D _ T O _ L A S T K N O W N G O O D  
 L a n g u a g e = E n g l i s h  
 T h e   s y s t e m   r e v e r t e d   t o   i t s   l a s t   k n o w n   g o o d   c o n f i g u r a t i o n .     T h e   s y s t e m   i s   r e s t a r t i n g . . . .  
 .  
  
 M e s s a g e I d = 7 0 0 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ B A D _ A C C O U N T _ N A M E  
 L a n g u a g e = E n g l i s h  
 N o   b a c k s l a s h   i s   i n   t h e   a c c o u n t   n a m e .  
 .  
  
 M e s s a g e I d = 7 0 0 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C O N N E C T I O N _ T I M E O U T  
 L a n g u a g e = E n g l i s h  
 T i m e o u t   ( % 1   m i l l i s e c o n d s )   w a i t i n g   f o r   t h e   % 2   s e r v i c e   t o   c o n n e c t .  
 .  
  
 M e s s a g e I d = 7 0 1 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ R E A D F I L E _ T I M E O U T  
 L a n g u a g e = E n g l i s h  
 T i m e o u t   ( % 1   m i l l i s e c o n d s )   w a i t i n g   f o r   R e a d F i l e .  
 .  
  
 M e s s a g e I d = 7 0 1 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ T R A N S A C T _ T I M E O U T  
 L a n g u a g e = E n g l i s h  
 T i m e o u t   ( % 1   m i l l i s e c o n d s )   w a i t i n g   f o r   a   t r a n s a c t i o n   r e s p o n s e   f r o m   t h e   % 2   s e r v i c e .  
 .  
  
 M e s s a g e I d = 7 0 1 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ T R A N S A C T _ I N V A L I D  
 L a n g u a g e = E n g l i s h  
 M e s s a g e   r e t u r n e d   i n   t r a n s a c t i o n   h a s   i n c o r r e c t   s i z e .  
 .  
  
 M e s s a g e I d = 7 0 1 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ F I R S T _ L O G O N _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 L o g o n   a t t e m p t   w i t h   c u r r e n t   p a s s w o r d   f a i l e d   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 1  
 .  
  
 M e s s a g e I d = 7 0 1 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E C O N D _ L O G O N _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 S e c o n d   l o g o n   a t t e m p t   w i t h   o l d   p a s s w o r d   a l s o   f a i l e d   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 1  
 .  
  
 M e s s a g e I d = 7 0 1 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ I N V A L I D _ D R I V E R _ D E P E N D E N C Y  
 L a n g u a g e = E n g l i s h  
 B o o t - s t a r t   o r   s y s t e m - s t a r t   d r i v e r   ( % 1 )   m u s t   n o t   d e p e n d   o n   a   s e r v i c e .  
 .  
  
 M e s s a g e I d = 7 0 1 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ B A D _ S E R V I C E _ S T A T E  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   h a s   r e p o r t e d   a n   i n v a l i d   c u r r e n t   s t a t e   % 2 .  
 .  
  
 M e s s a g e I d = 7 0 1 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C I R C U L A R _ D E P E N D E N C Y _ D E M A N D  
 L a n g u a g e = E n g l i s h  
 D e t e c t e d   c i r c u l a r   d e p e n d e n c i e s   d e m a n d   s t a r t i n g   % 1 .  
 .  
  
 M e s s a g e I d = 7 0 1 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ C I R C U L A R _ D E P E N D E N C Y _ A U T O  
 L a n g u a g e = E n g l i s h  
 D e t e c t e d   c i r c u l a r   d e p e n d e n c i e s   a u t o - s t a r t i n g   s e r v i c e s .  
 .  
  
 M e s s a g e I d = 7 0 1 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ D E P E N D _ O N _ L A T E R _ S E R V I C E  
 L a n g u a g e = E n g l i s h  
 C i r c u l a r   d e p e n d e n c y :   T h e   % 1   s e r v i c e   d e p e n d s   o n   a   s e r v i c e   i n   a   g r o u p   w h i c h   s t a r t s   l a t e r .  
 .  
  
 M e s s a g e I d = 7 0 2 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ D E P E N D _ O N _ L A T E R _ G R O U P  
 L a n g u a g e = E n g l i s h  
 C i r c u l a r   d e p e n d e n c y :   T h e   % 1   s e r v i c e   d e p e n d s   o n   a   g r o u p   w h i c h   s t a r t s   l a t e r .  
 .  
  
 M e s s a g e I d = 7 0 2 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E V E R E _ S E R V I C E _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 A b o u t   t o   r e v e r t   t o   t h e   l a s t   k n o w n   g o o d   c o n f i g u r a t i o n   b e c a u s e   t h e   % 1   s e r v i c e   f a i l e d   t o   s t a r t .  
 .  
  
 M e s s a g e I d = 7 0 2 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ H U N G  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   h u n g   o n   s t a r t i n g .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   7028A;0  ?@8  70?CA:5.  
 .  
  
 M e s s a g e I d = 7 0 2 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ E X I T _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   t e r m i n a t e d   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 2  
 .  
  
 M e s s a g e I d = 7 0 2 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ E X I T _ F A I L E D _ S P E C I F I C  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   t e r m i n a t e d   w i t h   s e r v i c e - s p e c i f i c   e r r o r   % 2 .  
 .  
  
 M e s s a g e I d = 7 0 2 5  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ A T _ B O O T _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 A t   l e a s t   o n e   s e r v i c e   o r   d r i v e r   f a i l e d   d u r i n g   s y s t e m   s t a r t u p .     U s e   E v e n t   V i e w e r   t o   e x a m i n e   t h e   e v e n t   l o g   f o r   d e t a i l s .  
 .  
  
 M e s s a g e I d = 7 0 2 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ B O O T _ S Y S T E M _ D R I V E R S _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   f o l l o w i n g   b o o t - s t a r t   o r   s y s t e m - s t a r t   d r i v e r ( s )   f a i l e d   t o   l o a d :   % 1  
 .  
  
 M e s s a g e I d = 7 0 2 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ R U N N I N G _ L A S T K N O W N G O O D  
 L a n g u a g e = E n g l i s h  
 R e a c t O S   c o u l d   n o t   b e   s t a r t e d   a s   c o n f i g u r e d .     A   p r e v i o u s   w o r k i n g   c o n f i g u r a t i o n   w a s   u s e d   i n s t e a d .  
 .  
  
 M e s s a g e I d = 7 0 2 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ T A K E _ O W N E R S H I P  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   R e g i s t r y   k e y   d e n i e d   a c c e s s   t o   S Y S T E M   a c c o u n t   p r o g r a m s   s o   t h e   S e r v i c e   C o n t r o l   M a n a g e r   t o o k   o w n e r s h i p   o f   t h e   R e g i s t r y   k e y .  
 .  
  
 M e s s a g e I d = 7 0 2 9  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = T I T L E _ S C _ M E S S A G E _ B O X  
 L a n g u a g e = E n g l i s h  
 S e r v i c e   C o n t r o l   M a n a g e r   % 0  
 .  
  
 M e s s a g e I d = 7 0 3 0  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ N O T _ I N T E R A C T I V E  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   i s   m a r k e d   a s   a n   i n t e r a c t i v e   s e r v i c e .     H o w e v e r ,   t h e   s y s t e m   i s   c o n f i g u r e d   t o   n o t   a l l o w   i n t e r a c t i v e   s e r v i c e s .     T h i s   s e r v i c e   m a y   n o t   f u n c t i o n   p r o p e r l y .  
 .  
  
 M e s s a g e I d = 7 0 3 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ C R A S H  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   t e r m i n a t e d   u n e x p e c t e d l y .     I t   h a s   d o n e   t h i s   % 2   t i m e ( s ) .     T h e   f o l l o w i n g   c o r r e c t i v e   a c t i o n   w i l l   b e   t a k e n   i n   % 3   m i l l i s e c o n d s :   % 5 .  
 .  
  
 M e s s a g e I d = 7 0 3 2  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ R E C O V E R Y _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   S e r v i c e   C o n t r o l   M a n a g e r   t r i e d   t o   t a k e   a   c o r r e c t i v e   a c t i o n   ( % 2 )   a f t e r   t h e   u n e x p e c t e d   t e r m i n a t i o n   o f   t h e   % 3   s e r v i c e ,   b u t   t h i s   a c t i o n   f a i l e d   w i t h   t h e   f o l l o w i n g   e r r o r :   % n % 4  
 .  
  
 M e s s a g e I d = 7 0 3 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S C E S R V _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   S e r v i c e   C o n t r o l   M a n a g e r   d i d   n o t   i n i t i a l i z e   s u c c e s s f u l l y .   T h e   s e c u r i t y  
 c o n f i g u r a t i o n   s e r v e r   ( s c e s r v . d l l )   f a i l e d   t o   i n i t i a l i z e   w i t h   e r r o r   % 1 .     T h e  
 s y s t e m   i s   r e s t a r t i n g . . .  
 .  
  
 M e s s a g e I d = 7 0 3 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ C R A S H _ N O _ A C T I O N  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   t e r m i n a t e d   u n e x p e c t e d l y .     I t   h a s   d o n e   t h i s   % 2   t i m e ( s ) .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   =5>6840==>  7025@H8;0AL.   -B>  ?@>87>H;>  % 2   @07( 0) .  
 .  
  
 M e s s a g e I d = 7 0 3 5  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ C O N T R O L _ S U C C E S S  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   w a s   s u c c e s s f u l l y   s e n t   a   % 2   c o n t r o l .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   CA?5H=>  >B?@028;0  " % 2 " .  
 .  
  
 M e s s a g e I d = 7 0 3 6  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A T U S _ S U C C E S S  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   e n t e r e d   t h e   % 2   s t a t e .  
 .  
 L a n g u a g e = R u s s i a n  
 !;C610  " % 1 "   ?5@5H;0  2  A>AB>O=85  " % 2 " .  
 .  
  
 M e s s a g e I d = 7 0 3 7  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ C O N F I G _ B A C K O U T _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   S e r v i c e   C o n t r o l   M a n a g e r   e n c o u n t e r e d   a n   e r r o r   u n d o i n g   a   c o n f i g u r a t i o n   c h a n g e  
 t o   t h e   % 1   s e r v i c e .     T h e   s e r v i c e ' s   % 2   i s   c u r r e n t l y   i n   a n   u n p r e d i c t a b l e   s t a t e .  
  
 I f   y o u   d o   n o t   c o r r e c t   t h i s   c o n f i g u r a t i o n ,   y o u   m a y   n o t   b e   a b l e   t o   r e s t a r t   t h e   % 1  
 s e r v i c e   o r   m a y   e n c o u n t e r   o t h e r   e r r o r s .     T o   e n s u r e   t h a t   t h e   s e r v i c e   i s   c o n f i g u r e d  
 p r o p e r l y ,   u s e   t h e   S e r v i c e s   s n a p - i n   i n   M i c r o s o f t   M a n a g e m e n t   C o n s o l e   ( M M C ) .  
 .  
  
 M e s s a g e I d = 7 0 3 8  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ F I R S T _ L O G O N _ F A I L E D _ I I  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   w a s   u n a b l e   t o   l o g   o n   a s   % 2   w i t h   t h e   c u r r e n t l y   c o n f i g u r e d  
 p a s s w o r d   d u e   t o   t h e   f o l l o w i n g   e r r o r :   % n % 3 % n % n T o   e n s u r e   t h a t   t h e   s e r v i c e   i s  
 c o n f i g u r e d   p r o p e r l y ,   u s e   t h e   S e r v i c e s   s n a p - i n   i n   M i c r o s o f t   M a n a g e m e n t  
 C o n s o l e   ( M M C ) .  
 .  
  
 M e s s a g e I d = 7 0 3 9  
 S e v e r i t y = W a r n i n g  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ D I F F E R E N T _ P I D _ C O N N E C T E D  
 L a n g u a g e = E n g l i s h  
 A   s e r v i c e   p r o c e s s   o t h e r   t h a n   t h e   o n e   l a u n c h e d   b y   t h e   S e r v i c e   C o n t r o l   M a n a g e r  
 c o n n e c t e d   w h e n   s t a r t i n g   t h e   % 1   s e r v i c e .     T h e   S e r v i c e   C o n t r o l   M a n a g e r   l a u n c h e d  
 p r o c e s s   % 2   a n d   p r o c e s s   % 3   c o n n e c t e d   i n s t e a d . % n % n  
  
 N o t e   t h a t   i f   t h i s   s e r v i c e   i s   c o n f i g u r e d   t o   s t a r t   u n d e r   a   d e b u g g e r ,   t h i s   b e h a v i o r   i s   e x p e c t e d .  
 .  
  
 M e s s a g e I d = 7 0 4 0  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T A R T _ T Y P E _ C H A N G E D  
 L a n g u a g e = E n g l i s h  
 T h e   s t a r t   t y p e   o f   t h e   % 1   s e r v i c e   w a s   c h a n g e d   f r o m   % 2   t o   % 3 .  
 .  
 L a n g u a g e = R u s s i a n  
 "8?  70?CA:0  A;C61K  " % 1 "   87<5=5=  A  " % 2 "   =0  " % 3 " .  
 .  
  
 M e s s a g e I d = 7 0 4 1  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ L O G O N _ T Y P E _ N O T _ G R A N T E D  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   w a s   u n a b l e   t o   l o g   o n   a s   % 2   w i t h   t h e   c u r r e n t l y   c o n f i g u r e d   p a s s w o r d   d u e   t o   t h e   f o l l o w i n g   e r r o r : % n  
 L o g o n   f a i l u r e :   t h e   u s e r   h a s   n o t   b e e n   g r a n t e d   t h e   r e q u e s t e d   l o g o n   t y p e   a t   t h i s   c o m p u t e r . % n % n  
 S e r v i c e :   % 1 % n  
 D o m a i n   a n d   a c c o u n t :   % 2 % n % n  
 T h i s   s e r v i c e   a c c o u n t   d o e s   n o t   h a v e   t h e   n e c e s s a r y   u s e r   r i g h t   " L o g   o n   a s   a   s e r v i c e . " % n % n  
 U s e r   A c t i o n % n % n  
 A s s i g n   " L o g   o n   a s   a   s e r v i c e "   t o   t h e   s e r v i c e   a c c o u n t   o n   t h i s   c o m p u t e r .   Y o u   c a n  
 u s e   L o c a l   S e c u r i t y   S e t t i n g s   ( S e c p o l . m s c )   t o   d o   t h i s .   I f   t h i s   c o m p u t e r   i s   a  
 n o d e   i n   a   c l u s t e r ,   c h e c k   t h a t   t h i s   u s e r   r i g h t   i s   a s s i g n e d   t o   t h e   C l u s t e r  
 s e r v i c e   a c c o u n t   o n   a l l   n o d e s   i n   t h e   c l u s t e r . % n % n  
 I f   y o u   h a v e   a l r e a d y   a s s i g n e d   t h i s   u s e r   r i g h t   t o   t h e   s e r v i c e   a c c o u n t ,   a n d   t h e  
 u s e r   r i g h t   a p p e a r s   t o   b e   r e m o v e d ,   a   G r o u p   P o l i c y   o b j e c t   a s s o c i a t e d   w i t h   t h i s  
 n o d e   m i g h t   b e   r e m o v i n g   t h e   r i g h t .   C h e c k   w i t h   y o u r   d o m a i n   a d m i n i s t r a t o r   t o   f i n d  
 o u t   i f   t h i s   i s   h a p p e n i n g .  
 .  
  
 M e s s a g e I d = 7 0 4 2  
 S e v e r i t y = I n f o r m a t i o n a l  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S T O P _ S U C C E S S _ W I T H _ R E A S O N  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   w a s   s u c c e s s f u l l y   s e n t   a   % 2   c o n t r o l . % n % n  
 T h e   r e a s o n   s p e c i f i e d   w a s :   % 3   [ % 4 ] % n % n  
 C o m m e n t :   % 5  
 .  
  
 M e s s a g e I d = 7 0 4 3  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ S E R V I C E _ S H U T D O W N _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 T h e   % 1   s e r v i c e   d i d   n o t   s h u t   d o w n   p r o p e r l y   a f t e r   r e c e i v i n g   a   p r e s h u t d o w n   c o n t r o l .  
 .  
  
  
 ;  
 ;   t r a n s p o r t   e v e n t s   9 0 0 0 - 9 4 9 9  
 ;  
  
 M e s s a g e I d = 9 0 0 4  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ T R A N S P O R T _ R E G I S T E R _ F A I L E D  
 L a n g u a g e = E n g l i s h  
 % 2   f a i l e d   t o   r e g i s t e r   i t s e l f   w i t h   t h e   N D I S   w r a p p e r .  
 .  
  
 M e s s a g e I d = 9 0 0 6  
 S e v e r i t y = E r r o r  
 F a c i l i t y = S y s t e m  
 S y m b o l i c N a m e = E V E N T _ T R A N S P O R T _ A D A P T E R _ N O T _ F O U N D  
 L a n g u a g e = E n g l i s h  
 % 2   c o u l d   n o t   f i n d   a d a p t e r   % 3 .  
 .  
 L a n g u a g e = R u s s i a n  
 " % 2 "   =5  A<>3;0  =09B8  040?B5@  " % 3 " .  
 .  
 