// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DKEnemy.h"
#include "DKBarrel.generated.h"

UCLASS()
class DONKEYKONG_API ADKBarrel : public ADKEnemy
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ladder Volume", meta = (AllowPrivateAccess = "true"))
	URotatingMovementComponent* RotMovement;
private:
	bool bMoveDirection;
	bool bChangeDirection;
	bool bMovingOnLadder;
protected:
	/* In which direction (and how far) from barrel we will check for floor. */
	UPROPERTY(EditAnywhere, Category = "Config")
		float TraceStartDistance;

	/* Direction and magnitude in which barrel will move on start. */
	UPROPERTY(EditAnywhere, Category = "Config")
		float Move;

	/* Mgnitude of how fast barrel will fall when reach end of floor; */
	UPROPERTY(EditAnywhere, Category = "Config")
		float Falling;

	/* Rotation rate (direction and magnitude). */
	UPROPERTY(EditAnywhere, Category = "Config")
		FRotator RotationRate;
public:	
	// Sets default values for this actor's properties
	ADKBarrel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/* Get chance (0-1), in which barrel will move down on barrel. */
	
	inline void SetMovingOnLadder(bool ValueIn) { bMovingOnLadder = ValueIn; };
	
	/** ADKEnemy overrides - BEGIN */
	virtual void ClimbDown(class ADKLadder* LadderIn) override;

	virtual void ClimbStop(class ADKLadder* LadderIn) override;
	/* ADKEnemy overrides - END **/
	
	/* Kill enemy. */
	virtual void Kill(class ADKPlayerController* WhoKilled) override;
protected:
	/* Looks for floor, to which barrel can stick. */
	bool GetFloor(FHitResult& out);
};
