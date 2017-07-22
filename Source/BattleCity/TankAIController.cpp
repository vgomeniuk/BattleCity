// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankAIController.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* Enemy = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Enemy) {
		MoveToActor(Enemy, AcceptanceRadius);
		ControlledTank->AimAt(Enemy->GetActorLocation());
		ControlledTank->Fire();
	}
}
