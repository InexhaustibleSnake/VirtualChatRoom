// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VCRBaseHUD.generated.h"

class UVCRBaseWidget;
class UWidgetBlueprint;

UCLASS()
class VIRTUALCHATROOM_API AVCRBaseHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

protected:
    void CreateInGameWidget();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> InGameWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    UUserWidget* InGameWidget;
};
