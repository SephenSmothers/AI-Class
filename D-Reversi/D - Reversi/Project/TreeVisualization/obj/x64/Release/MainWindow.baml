   M S B A M L   `   `   `  ���� T  PWPFExtensions, Version=1.1.0.0, Culture=neutral, PublicKeyToken=39de8b1cac8f3dd4V;clr-namespace:WPFExtensions.Controls;assembly=WPFExtensionsWPFExtensions.Controls  ] YGraphviz4Net.WPF.TreeVisualization, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullW0clr-namespace:Graphviz4Net.WPF.TreeVisualization"Graphviz4Net.WPF.TreeVisualization W SGraphviz4Net.WPF, Version=1.0.0.0, Culture=neutral, PublicKeyToken=4b46ae066952113aM8clr-namespace:Graphviz4Net.WPF;assembly=Graphviz4Net.WPFGraphviz4Net.WPF cCclr-namespace:Graphviz4Net.WPF.ViewModels;assembly=Graphviz4Net.WPFGraphviz4Net.WPF.ViewModels Y UFullSailAFI.GamePlaying.CoreAI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullwTclr-namespace:FullSailAFI.GamePlaying.CoreAI;assembly=FullSailAFI.GamePlaying.CoreAIFullSailAFI.GamePlaying.CoreAI 3   -Graphviz4Net.WPF.TreeVisualization.MainWindow   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     :i,http://schemas.microsoft.com/winfx/2006/xaml     PControls;clr-namespace:WPFExtensions.Controls;assembly=WPFExtensions     NTreeVisualization0clr-namespace:Graphviz4Net.WPF.TreeVisualization     HWPF8clr-namespace:Graphviz4Net.WPF;assembly=Graphviz4Net.WPF     Z
ViewModelsCclr-namespace:Graphviz4Net.WPF.ViewModels;assembly=Graphviz4Net.WPF     gCoreAITclr-namespace:FullSailAFI.GamePlaying.CoreAI;assembly=FullSailAFI.GamePlaying.CoreAI     -     � Title$9  3Minimax tree visualization with Graphiz4Net and WPF������ *WindowHeight+ �� Mode$ OneWayToSource=����� *WindowWidth+$ OneWayToSource=� � 	Resources >  8Graphviz4Net.WPF.TreeVisualization.BoolToStringConverter   boolToYesNoConverter�  �Graphviz4Net.WPF.TreeVisualization.BoolToValueConverter`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   
FalseValue   	TrueValue  boolToRunningColorConverter?  9Graphviz4Net.WPF.TreeVisualization.EnumToBooleanConverter  enumConverter �� DataType0  *FullSailAFI.GamePlaying.CoreAI.NodeRegular �� Padding �� CornerRadius �� Orientation	 �� StringFormat
 �� Triggers �� Value �� Binding �� 
TargetName �� Property �� Value-  'FullSailAFI.GamePlaying.CoreAI.NodeMcts2  ,FullSailAFI.GamePlaying.CoreAI.NodeAlphaBeta8  2FullSailAFI.GamePlaying.CoreAI.NodeAlphaBetaPruned �� 
TargetType  RadioButtonStyle �� 
TargetType �� Triggers P� Property P� Value �� Triggers �� RelativeSource �� Path9  3Graphviz4Net.WPF.ViewModels.EdgeArrowLabelViewModel/	  )Graphviz4Net.WPF.ViewModels.EdgeViewModel � ToolTip4
  .Graphviz4Net.WPF.ViewModels.EdgeLabelViewModel.  (Graphviz4Net.WPF.TreeVisualization.Arrow��%�  &	        &	      &	 ?     (�� D     *, +)(�� �    *, +)(�� �    *, +)(�� *    *, +)&	 �    '��      (�� �    *, +)(�� �    *,	 +)(�� 0    *,
 +)(�� �    *, +)  $ No��$	 Yes��  $ Crimson��$ DarkGoldenrod��  �� "  .R��� $ 2q�$ 5��
����������� *NodeHighlightColor+���� *NodeHighlightBorderSize+._��� $ Vertical=�.+��� ���� *
NodePlayer+$	 	Curr: {0}���� ���� *NodeNextPlayer+$	 	Next: {0}���� ���� *	NodeRow+$	 Row: {0}���� ���� *
NodeColumn+$	 Col: {0}���� $
��Rank������ *
NodeRank+$	 	Rank: {0}���� ���� *NodeId+$	 ID: {0}��
 �� $
 True�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� $ False�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� "  .R��� $ 2q�$ 5��
����������� *NodeHighlightColor+���� *NodeHighlightBorderSize+._��� $ Vertical=�.+��� ���� *
NodePlayer+$	 	Curr: {0}���� ���� *NodeNextPlayer+$	 	Next: {0}���� ���� *	NodeRow+$	 Row: {0}���� ���� *
NodeColumn+$	 Col: {0}���� $
��Rank������ *
NodeRank+$	 W Wins: {0:0.00}%���� ���� *NodeId+$	 ID: {0}��
 �� $
 True�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� $ False�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� "  .R��� $ 2q�$ 5��
����������� *NodeHighlightColor+���� *NodeHighlightBorderSize+._��� $ Vertical=�.+��� ���� *
NodePlayer+$	 	Curr: {0}���� ���� *NodeNextPlayer+$	 	Next: {0}���� ���� *	NodeRow+$	 Row: {0}���� ���� *
NodeColumn+$	 Col: {0}���� $
��Rank������ *
NodeRank+$	 	Rank: {0}���� $��Alpha������ *	NodeAlpha+$	 
Alpha: {0}���� $
��Beta������ *
NodeBeta+$	 	Beta: {0}���� ���� *NodeId+$	 ID: {0}��
 �� $
 True�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� $ False�� �� *NodeHasRankHighlight+.a��� $
 Rank�� � ��
 ������� $
 True�� �� *NodeHasAlphaHighlight+.a��� $ Alpha�� � ��
 ������� $ False�� �� *NodeHasAlphaHighlight+.a��� $ Alpha�� � ��
 ������� $
 True�� �� *NodeHasBetaHighlight+.a��� $
 Beta�� � ��
 ��ح��� $ False�� �� *NodeHasBetaHighlight+.a��� $
 Beta�� � ��
 ������� $
 True�� �� *NodeHasAlphaStrikethrough+.a��� $ Alpha�� � ��$ Strikethrough{��� $ Alpha�� � ��
 �  ���� $ False�� �� *NodeHasAlphaStrikethrough+.a��� $ Alpha�� � ��$
 None{��� $ Alpha�� � ��
 �   ��� $
 True�� �� *NodeHasBetaStrikethrough+.a��� $
 Beta�� � ��$ Strikethrough{��� $
 Beta�� � ��
 �  ���� $ False�� �� *NodeHasBetaStrikethrough+.a��� $
 Beta�� � ��$
 None{��� $
 Beta�� � ��
 �   ��� "  .R��� $ 2q�$ 5��
����������� *NodeHighlightColor+���� *NodeHighlightBorderSize+._��� $ Vertical=�.+��� ���� *
NodePlayer+$	 	Curr: {0}���� ���� *NodeNextPlayer+$	 	Next: {0}���� ���� *	NodeRow+$	 Row: {0}���� ���� *
NodeColumn+$	 Col: {0}���� ���� *NodeId+$	 ID: {0}���� " 	�.���  � �� �� " 	�.R��� $��radioButtonBorder��$ 5��
�������$��1q�
���   �._��� #��z�� P�  �@J�IsMouseOver . . ��� $ radioButtonBorder�� � ��
 �����P�  �@d�	IsChecked$
 TrueY�. ��� $ radioButtonBorder�� � ��
 �����P�  � {� .  . ��� $ radioButtonBorder�� � ��
 �  ���� " �� P�  �@=�HasError . . ���  �@�ToolTip ��  �� *Self+$) #(Validation.Errors)[0].ErrorContent��� "  .R��� 
����������� $ Label��� " 	 .R�F� $��2������ *Data+���� *&$Edge.Destination.NodeParentEdgeColor+ �� *
Edge.Label+�� " 
 .R��� .+��� $��Comic Sans MS)����� *Edge.Destination.NodeMinMax+���� *&$Edge.Destination.NodeParentEdgeColor+�� "  .R�F� ����        �    ��� 	$��2������ *	EdgeColor+.���  � RowDefinitions �� $��20 ��� $��99 ��� $��* � � ColumnDefinitions �� $��95 ��� $	��234 ��� $��* �.+�(   "WPFExtensions.Controls.ZoomControl  $��0��$��3��$��0��$��3��.��"  Graphviz4Net.WPF.GraphLayout  -     Name$ GraphLayout��(   !UseContentPresenterForAllElements .    LogGraphvizOutput .    Graph �� *	TreeGraph+ ��%`   '�       �� " �.���  � �� �� " �.R��� 
���   �Generating the layout...�� $ 5�����	#88C0C0C0$��1��$��1��._��� $ Vertical=�$��7q�.+��� $ 
Horizontal=�$��0q�.+��� $��
0, 0, 5, 0q�.+�	� -   $��SingleStepButton�� 	� 	GroupName$
 Mode��$��40��$��40��$��4q�$	��Top=�  ^� ShowOnDisabled  . #��[ {��� $ 	IsRunning�! d� 	IsChecked! �� $ TreeVisualizationMode�$ TwoWay=�" �� 	Converter#" [ :  4Graphviz4Net.WPF.TreeVisualization.VisualizationMode#   
SingleStep$ �� ConverterParameter#$ Z# ���� $��../icons/play_pause.png��$��UniformToFill=� _� .���� .+��� $
��Bold"�Single Step�� *(Moves visualization forward one command.�� $��
0, 0, 5, 0q�.+�	� -   $��PauseButton��$
 Mode��$��40��$��40��$��4q�$	��Top=�  . #��[ {��� $ 	IsRunning�! �� $ TreeVisualizationMode�$ TwoWay=�#" [ %   Pause#$ Z% ���� $��../icons/pause.png��$��UniformToFill=� _� .���� .+��� $
��Bold"�Pause�� Pauses visualization.�� $��
0, 0, 5, 0q�.+�	� -   $��StepByStepButton��$
 Mode��$��40��$��40��$��4q�$	��Top=�  . #��[ {��� $ 	IsRunning�! �� $ TreeVisualizationMode�$ TwoWay=�#" [ &   
StepByStep#$ Z& ���� $��../icons/play.png��$��UniformToFill=� _� .���� .+��� $
��Bold"�Step-By-Step�� <:Moves visualization forward one command at a regular rate.�� $��
0, 0, 5, 0q�.+�	� -   $��FastForwardButton��$
 Mode��$��40��$��40��$��4q�$	��Top=�  . #��[ {��� $ 	IsRunning�! �� $ TreeVisualizationMode�$ TwoWay=�#" [ '   FastForward#$ Z' ���� $#��../icons/play_fastforward.png��$��UniformToFill=� _� .���� .+��� $
��Bold"�Fast Forward�� +)Moves visualization forward at max speed.�� $��
0, 0, 0, 0q�.+�	� -   $��	EndButton��$
 Mode��$��40��$��40��$��4q�$	��Top=�  . #��[ {��� $ 	IsRunning�! �� $ TreeVisualizationMode�$ TwoWay=�#" [ (   	SkipToEnd#$ Z( ���� $��../icons/play_end.png��$��UniformToFill=� _� .���� .+��� $
��Bold"�Skip To End�� =;Moves visualization forward at max speed without rendering.�� (&Rendering will happen once at the end.�� $ 
Horizontal=�.+��� $
��Bold"�$��
0, 6, 0, 0q�Step-By-Step rate:�� $��
6, 6, 3, 0q�) �� TextAlignment$) Right=�$��50������ *StepByStepRateString+* �� ValidatesOnDataErrors* . + �� UpdateSourceTrigger$+ PropertyChanged=��� $
��Bold"�$��
0, 6, 0, 0q�(ms)�� $ 
Horizontal=�.+��� $
��Bold"�$��
0, 6, 0, 0q�Visualization running?�� $
��Bold"�$��10, 6, 0, 0q����� $ 	IsRunning�#" [ ���� $ 	IsRunning�#" [  