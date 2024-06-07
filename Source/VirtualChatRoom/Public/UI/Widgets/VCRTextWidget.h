// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRTextWidget.generated.h"

class UTextBlock;

UCLASS()
class VIRTUALCHATROOM_API UVCRTextWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

public:
    virtual void NativePreConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetWidgetText(const FText& Text);

protected:
    UPROPERTY(meta = (BindWidget), BlueprintReadWrite, Category = "UI")
    UTextBlock* TextBlock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    FText WidgetText;
};
