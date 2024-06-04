// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VCRBaseHUD.generated.h"

class UVCRBaseWidget;

UCLASS()
class VIRTUALCHATROOM_API AVCRBaseHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

protected:
    void CreateInGameWidget();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UVCRBaseWidget> InGameWidget;
};
