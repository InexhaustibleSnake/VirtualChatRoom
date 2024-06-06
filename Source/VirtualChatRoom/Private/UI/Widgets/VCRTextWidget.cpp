// This project is made for a test assignment

#include "UI/Widgets/VCRTextWidget.h"
#include "Components/TextBlock.h"

void UVCRTextWidget::NativePreConstruct()
{
    Super::NativePreConstruct();

    SetWidgetText(WidgetText);
}

void UVCRTextWidget::SetWidgetText(const FText& Text)
{
    WidgetText = Text;

    if (!TextBlock) return;

    TextBlock->SetText(WidgetText);
}
