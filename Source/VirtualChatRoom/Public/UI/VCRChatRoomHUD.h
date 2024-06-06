// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/VCRBaseHUD.h"
#include "VCRChatRoomHUD.generated.h"

UCLASS()
class VIRTUALCHATROOM_API AVCRChatRoomHUD : public AVCRBaseHUD
{
    GENERATED_BODY()

public:
    AVCRChatRoomHUD();

protected:
    virtual void BeginPlay() override;
};
