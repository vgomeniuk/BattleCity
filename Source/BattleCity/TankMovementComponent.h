// Vikutator Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTrackComponent;

UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = (Action))
class BATTLECITY_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTrackComponent* Left, UTrackComponent* Right);

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Move(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Turn(float Throw);

private:
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTrackComponent* Left = nullptr;
	UTrackComponent* Right = nullptr;

};
