   M S B A M L   `   `   `  ����T  PWPFExtensions, Version=1.1.0.0, Culture=neutral, PublicKeyToken=39de8b1cac8f3dd4V;clr-namespace:WPFExtensions.Controls;assembly=WPFExtensionsWPFExtensions.Controls  5   	   ] YGraphviz4Net.WPF.TreeVisualization, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullW0clr-namespace:Graphviz4Net.WPF.TreeVisualization"Graphviz4Net.WPF.TreeVisualization 5   	   W SGraphviz4Net.WPF, Version=1.0.0.0, Culture=neutral, PublicKeyToken=4b46ae066952113aM8clr-namespace:Graphviz4Net.WPF;assembly=Graphviz4Net.WPFGraphviz4Net.WPF 5   	   cCclr-namespace:Graphviz4Net.WPF.ViewModels;assembly=Graphviz4Net.WPFGraphviz4Net.WPF.ViewModels 5   	   Y UFullSailAFI.GamePlaying.CoreAI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullwTclr-namespace:FullSailAFI.GamePlaying.CoreAI;assembly=FullSailAFI.GamePlaying.CoreAIFullSailAFI.GamePlaying.CoreAI 5	   	   3   -Graphviz4Net.WPF.TreeVisualization.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   :i,http://schemas.microsoft.com/winfx/2006/xaml     5   	   PControls;clr-namespace:WPFExtensions.Controls;assembly=WPFExtensions     5   	   NTreeVisualization0clr-namespace:Graphviz4Net.WPF.TreeVisualization     5   	   HWPF8clr-namespace:Graphviz4Net.WPF;assembly=Graphviz4Net.WPF     5   	   Z
ViewModelsCclr-namespace:Graphviz4Net.WPF.ViewModels;assembly=Graphviz4Net.WPF     5   	   gCoreAITclr-namespace:FullSailAFI.GamePlaying.CoreAI;assembly=FullSailAFI.GamePlaying.CoreAI     5	   	   -   5          � Title$9  3Minimax tree visualization with Graphiz4Net and WPF��5
   	   ��5   	   �� *WindowHeight+ �� Mode$ OneWayToSource=���5   	   �� *WindowWidth+$ OneWayToSource=� � 	Resources 5      >  8Graphviz4Net.WPF.TreeVisualization.BoolToStringConverter   boolToYesNoConverter�  �Graphviz4Net.WPF.TreeVisualization.BoolToValueConverter`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   
FalseValue   	TrueValue  boolToRunningColorConverter?  9Graphviz4Net.WPF.TreeVisualization.EnumToBooleanConverter  enumConverter �� DataType0  *FullSailAFI.GamePlaying.CoreAI.NodeRegular �� Padding �� CornerRadius �� Orientation	 �� StringFormat
 �� Triggers �� Value �� Binding �� 
TargetName �� Property �� Value-  'FullSailAFI.GamePlaying.CoreAI.NodeMcts2  ,FullSailAFI.GamePlaying.CoreAI.NodeAlphaBeta8  2FullSailAFI.GamePlaying.CoreAI.NodeAlphaBetaPruned �� 
TargetType  RadioButtonStyle �� 
TargetType �� Triggers P� Property P� Value �� Triggers �� RelativeSource �� Path9  3Graphviz4Net.WPF.ViewModels.EdgeArrowLabelViewModel/	  )Graphviz4Net.WPF.ViewModels.EdgeViewModel � ToolTip4
  .Graphviz4Net.WPF.ViewModels.EdgeLabelViewModel.  (Graphviz4Net.WPF.TreeVisualization.Arrow��%\  &	        &	 /     &	 m     (�� �     5      *, +)(�� �    5-      *, +)(�� f    5C      *, +)(�� �    5|      *, +)&	 �    '�� '    (�� �    5�      *, +)(�� X    5�      *,	 +)(��     5�      *,
 +)(�� �    5�      *, +)  5   
   $ No��5   *   $	 Yes��6:     5   
   $ Crimson��5   1   $ DarkGoldenrod��6F     5   
   5      �� 5   
   "  6   .R�5      �� $ 2q�6   $ 5��6!   
���������5      �� *NodeHighlightColor+��5      �� *NodeHighlightBorderSize+._�5      �� $ Vertical=�6   .+�5      �� ��6    �� *
NodePlayer+$	 	Curr: {0}���� 5      ��6    �� *NodeNextPlayer+$	 	Next: {0}���� 5      ��6    �� *	NodeRow+$	 Row: {0}���� 5      ��6    �� *
NodeColumn+$	 Col: {0}���� 5      $
��Rank��6    ��6,   �� *
NodeRank+$	 	Rank: {0}���� 5!      ��6    �� *NodeId+$	 ID: {0}��5"      5#      
 5$      �� 5%      $
 True��6G    6   �� *NodeHasRankHighlight+.a�5&      �� $
 Rank��6    � ��
 �����6O   5'      �� 5(      $ False��6G    6   �� *NodeHasRankHighlight+.a�5)      �� $
 Rank��6    � ��
 �����6O   5*      5,      �� 5-   
   "  6   .R�5.      �� $ 2q�6   $ 5��6!   
���������5/      �� *NodeHighlightColor+��50      �� *NodeHighlightBorderSize+._�51      �� $ Vertical=�6   .+�52      �� ��6    �� *
NodePlayer+$	 	Curr: {0}���� 53      ��6    �� *NodeNextPlayer+$	 	Next: {0}���� 54      ��6    �� *	NodeRow+$	 Row: {0}���� 55      ��6    �� *
NodeColumn+$	 Col: {0}���� 56      $
��Rank��6    ��6,   �� *
NodeRank+$	 W Wins: {0:0.00}%���� 57      ��6    �� *NodeId+$	 ID: {0}��58      59      
 5:      �� 5;      $
 True��6G    6   �� *NodeHasRankHighlight+.a�5<      �� $
 Rank��6    � ��
 �����6O   5=      �� 5>      $ False��6G    6   �� *NodeHasRankHighlight+.a�5?      �� $
 Rank��6    � ��
 �����6O   5@      5B      �� 5C   
   "  6   .R�5D      �� $ 2q�6   $ 5��6!   
���������5E      �� *NodeHighlightColor+��5F      �� *NodeHighlightBorderSize+._�5G      �� $ Vertical=�6   .+�5H      �� ��6    �� *
NodePlayer+$	 	Curr: {0}���� 5I      ��6    �� *NodeNextPlayer+$	 	Next: {0}���� 5J      ��6    �� *	NodeRow+$	 Row: {0}���� 5K      ��6    �� *
NodeColumn+$	 Col: {0}���� 5L      $
��Rank��6    ��6,   �� *
NodeRank+$	 	Rank: {0}���� 5N      $��Alpha��6    ��6-   �� *	NodeAlpha+$	 
Alpha: {0}��5P      �� 5Q      $
��Beta��6    ��6,   �� *
NodeBeta+$	 	Beta: {0}��5S      �� 5T      ��6    �� *NodeId+$	 ID: {0}��5U      5V      
 5W      �� 5X      $
 True��6G    6   �� *NodeHasRankHighlight+.a�5Y      �� $
 Rank��6    � ��
 �����6O   5Z      �� 5[      $ False��6G    6   �� *NodeHasRankHighlight+.a�5\      �� $
 Rank��6    � ��
 �����6O   5]      �� 5^      $
 True��6H    6   �� *NodeHasAlphaHighlight+.a�5_      �� $ Alpha��6    � ��
 �����6P   5`      �� 5a      $ False��6H    6   �� *NodeHasAlphaHighlight+.a�5b      �� $ Alpha��6    � ��
 �����6P   5c      �� 5d      $
 True��6G    6   �� *NodeHasBetaHighlight+.a�5e      �� $
 Beta��6    � ��
 ��ح�6O   5f      �� 5g      $ False��6G    6   �� *NodeHasBetaHighlight+.a�5h      �� $
 Beta��6    � ��
 �����6O   5i      �� 5j      $
 True��6L    6   �� *NodeHasAlphaStrikethrough+.a�5k      �� $ Alpha��6    � ��$ Strikethrough{�6U   �� 5l      $ Alpha��6    � ��
 �  ��6P   5m      �� 5n      $ False��6L    6   �� *NodeHasAlphaStrikethrough+.a�5o      �� $ Alpha��6    � ��$
 None{�6U   �� 5p      $ Alpha��6    � ��
 �   �6P   5q      �� 5r      $
 True��6K    6   �� *NodeHasBetaStrikethrough+.a�5s      �� $
 Beta��6    � ��$ Strikethrough{�6T   �� 5t      $
 Beta��6    � ��
 �  ��6O   5u      �� 5v      $ False��6K    6   �� *NodeHasBetaStrikethrough+.a�5w      �� $
 Beta��6    � ��$
 None{�6T   �� 5x      $
 Beta��6    � ��
 �   �6O   5y      5{      �� 5|   
   "  6   .R�5}      �� $ 2q�6   $ 5��6!   
���������5~      �� *NodeHighlightColor+��5      �� *NodeHighlightBorderSize+._�5�      �� $ Vertical=�6   .+�5�      �� ��6    �� *
NodePlayer+$	 	Curr: {0}���� 5�      ��6    �� *NodeNextPlayer+$	 	Next: {0}���� 5�      ��6    �� *	NodeRow+$	 Row: {0}���� 5�      ��6    �� *
NodeColumn+$	 Col: {0}���� 5�      ��6    �� *NodeId+$	 ID: {0}��5�      5�      5�      �� 5�   
   " 	�6   .�5�      ��  � �� 5�      �� 5�      " 	�6&   .R�5�      �� $��radioButtonBorder��6!   $ 5��6:   
�������$��1q�6_   
���   �._�5�      �� #��z��6/   5�       5�      P� 5�       �@J�IsMouseOver . . �5�   "   �� $ radioButtonBorder��6)    � ��
 �����6^   5�      P� 5�       �@d�	IsChecked$
 TrueY�6;   . �5�   "   �� $ radioButtonBorder��6)    � ��
 �����6^   5�      P� 5�       � {� .  . �5�   "   �� $ radioButtonBorder��6)    � ��
 �  ��6_   5�      5�      5�      5�      �� 5�   
   " ��6    5�      P� 5�       �@=�HasError . . �5�      ��  �@�ToolTip 5�      ��  �� *Self+$) #(Validation.Errors)[0].ErrorContent�5�      5�      5�      �� 5�   
   "  6   .R�5�      �� 
���������6   �� $ Label�64   5�      �� 5�   
   " 	 6   .R�5�      F� $��2��5�      ��5�      �� *Data+��5�      �� *&$Edge.Destination.NodeParentEdgeColor+ 5�   '   �� *
Edge.Label+5�      �� 5�   
   " 
 6   .R�5�      �� .+�5�      �� $��Comic Sans MS)�6I   ��6   �� *Edge.Destination.NodeMinMax+��5�      �� *&$Edge.Destination.NodeParentEdgeColor+5�      5�      �� 5�   
   "  6   .R�5�      F� ����        �    ��� 	$��2��5�   0   ��6   �� *	EdgeColor+5�      5�      5�      .��5�      �  � RowDefinitions 5�   
   �� 5�      $��20 �6   �� 5�      $��99 �6   �� 5�      $��* �6    � ColumnDefinitions 5�   
   �� 5�      $��95 �6   �� 5�      $	��234 �6   �� 5�      $��* �6   .+�5�   
   (   "WPFExtensions.Controls.ZoomControl  $��0��6   $��3��6,   $��0��6=   $��3��6M   .��5�      "  Graphviz4Net.WPF.GraphLayout  -   5          Name$ GraphLayout��5�      (   !UseContentPresenterForAllElements .    LogGraphvizOutput .    Graph 5�      �� *	TreeGraph+ 5�      ��%�   '�       �� 5�      " �6   .�5�      ��  � �� 5�      �� 5�   "   " �62   .R�5�   &   �� 
���   �Generating the layout...6]   5�   #   5�      5�      5�      5�      5�      �� 5�   
   $ 5��6   ���	#88C0C0C0$��1��69   $��1��6F   ._�5�      �� $ Vertical=�6   $��7q�60   .+�5�      �� $ 
Horizontal=�6   $��0q�66   .+�5�      �� $��
0, 0, 5, 0q�6!   .+�5�      	� -   5        $��SingleStepButton��5�   &    	� 	GroupName$
 Mode��6>   $��40��5�   !   $��40��6-   $��4q�68   $	��Top=�6D     ^� ShowOnDisabled  . #��[ 5�   !   {�5�   !   �� $ 	IsRunning�! d� 	IsChecked! 5�   !   �� $ TreeVisualizationMode�$ TwoWay=�" �� 	Converter#" [ :  4Graphviz4Net.WPF.TreeVisualization.VisualizationMode#   
SingleStep$ �� ConverterParameter#$ Z# ��5�      �� 5�   "   $��../icons/play_pause.png��6(   $��UniformToFill=�6I    5�      _� 5�   "   .��5�   &   �� .+�5   *   �� $
��Bold"�64   Single Step6S   �� 5  *   *(Moves visualization forward one command.6^   5  '   5  #   5     5     �� 5     $��
0, 0, 5, 0q�6!   .+�5     	� -   5        $��PauseButton��5  &   $
 Mode��69   $��40��5	  !   $��40��6-   $��4q�68   $	��Top=�6D     . #��[ 5  !   {�5  !   �� $ 	IsRunning�! 5  !   �� $ TreeVisualizationMode�$ TwoWay=�#" [ %   Pause#$ Z% ��5     �� 5  "   $��../icons/pause.png��6(   $��UniformToFill=�6D    5     _� 5  "   .��5  &   �� .+�5  *   �� $
��Bold"�64   Pause6M   �� 5  *   Pauses visualization.6K   5  '   5  #   5     5     �� 5     $��
0, 0, 5, 0q�6!   .+�5     	� -   5        $��StepByStepButton��5  &   $
 Mode��6>   $��40��5  !   $��40��6-   $��4q�68   $	��Top=�6D     . #��[ 5"  !   {�5!  !   �� $ 	IsRunning�! 5#  !   �� $ TreeVisualizationMode�$ TwoWay=�#" [ &   
StepByStep#$ Z& ��5&     �� 5'  "   $��../icons/play.png��6(   $��UniformToFill=�6C    5)     _� 5*  "   .��5+  &   �� .+�5,  *   �� $
��Bold"�64   Step-By-Step6T   �� 5-  *   <:Moves visualization forward one command at a regular rate.6p   5.  '   5/  #   51     52     �� 53     $��
0, 0, 5, 0q�6!   .+�54     	� -   5        $��FastForwardButton��54  &   $
 Mode��6?   $��40��55  !   $��40��6-   $��4q�68   $	��Top=�6D     . #��[ 58  !   {�57  !   �� $ 	IsRunning�! 59  !   �� $ TreeVisualizationMode�$ TwoWay=�#" [ '   FastForward#$ Z' ��5<     �� 5=  "   $#��../icons/play_fastforward.png��6(   $��UniformToFill=�6O    5?     _� 5@  "   .��5A  &   �� .+�5B  *   �� $
��Bold"�64   Fast Forward6T   �� 5C  *   +)Moves visualization forward at max speed.6_   5D  '   5E  #   5G     5H     �� 5I     $��
0, 0, 0, 0q�6!   .+�5J     	� -   5        $��	EndButton��5J  &   $
 Mode��67   $��40��5K  !   $��40��6-   $��4q�68   $	��Top=�6D     . #��[ 5N  !   {�5M  !   �� $ 	IsRunning�! 5O  !   �� $ TreeVisualizationMode�$ TwoWay=�#" [ (   	SkipToEnd#$ Z( ��5R     �� 5S  "   $��../icons/play_end.png��6(   $��UniformToFill=�6G    5U     _� 5V  "   .��5W  &   �� .+�5X  *   �� $
��Bold"�64   Skip To End6S   �� 5Y  *   =;Moves visualization forward at max speed without rendering.�� 6p   (&Rendering will happen once at the end.5Z  \   5[  '   5\  #   5^     5_     5`     �� 5a     $ 
Horizontal=�6   .+�5b     �� $
��Bold"�6    $��
0, 6, 0, 0q�62   Step-By-Step rate:6Z   �� 5c     $��
6, 6, 3, 0q�6   ) �� TextAlignment$) Right=�5e     $��50��64   ��5d     �� *StepByStepRateString+* �� ValidatesOnDataErrors* . + �� UpdateSourceTrigger$+ PropertyChanged=�5e  4   �� 5f     $
��Bold"�6    $��
0, 6, 0, 0q�62   (ms)6L   5g     �� 5h     $ 
Horizontal=�6   .+�5i     �� $
��Bold"�6    $��
0, 6, 0, 0q�62   Visualization running?6^   �� 5j     $
��Bold"�6    $��10, 6, 0, 0q�62   ��5k      �� $ 	IsRunning�#" [ ��5l      �� $ 	IsRunning�#" [  5m     5n     5o     5p     5q     