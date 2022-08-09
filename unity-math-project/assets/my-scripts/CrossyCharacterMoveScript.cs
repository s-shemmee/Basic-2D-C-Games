using UnityEngine;
using System.Collections;

public class CrossyCharacterMoveScript : MonoBehaviour {

	private GameObject jumpPoint1;
	private GameObject jumpPoint2;
	private GameObject jumpPoint3;
	private GameObject jumpPoint4;
	private GameObject jumpPoint5;
	private GameObject jumpPoint6;
	private Vector3 JumpTargetLocation;
	private float JumpMidPointLocation;
	public float jumpHeightIncrement = 10;

	public float jumpSpeed = 20;
	private float initialJumpHeight;

	private bool isJumping = false;


	int currentJumpPointNumber;
	// Use this for initialization
	void Start () {
		jumpPoint1 = GameObject.Find ("jumpPoint1");
		jumpPoint2 = GameObject.Find ("jumpPoint2");
		jumpPoint3 = GameObject.Find ("jumpPoint3");
		jumpPoint4 = GameObject.Find ("jumpPoint4");
		jumpPoint5 = GameObject.Find ("jumpPoint5");
		jumpPoint6 = GameObject.Find ("jumpPoint6");

		currentJumpPointNumber = 1;

		this.transform.position = new Vector3 (jumpPoint1.transform.position.x, this.transform.position.y, this.transform.position.z);
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown (0)) {
			if(!isJumping)
			{
				StartJump ();
			}
		}

		if (isJumping) {
			this.transform.position = new Vector3(this.transform.position.x - jumpSpeed * Time.deltaTime, this.transform.position.y, this.transform.position.z);
			if(this.transform.position.x < JumpTargetLocation.x)
			{
				isJumping = false;
				this.transform.position = new Vector3(this.transform.position.x, initialJumpHeight, this.transform.position.z);

			}
			if(isJumping)
			{
				if(this.transform.position.x > JumpMidPointLocation) {
					this.transform.position = new Vector3(this.transform.position.x, this.transform.position.y + jumpHeightIncrement * Time.deltaTime, this.transform.position.z);
				}
				else {				
					this.transform.position = new Vector3(this.transform.position.x, this.transform.position.y - jumpHeightIncrement * Time.deltaTime, this.transform.position.z);
				}
			}
		}
	}

	void StartJump()
	{
		isJumping = true;
		currentJumpPointNumber += 1;
		if (currentJumpPointNumber > 6) {
			currentJumpPointNumber = 1;
		}

		switch (currentJumpPointNumber) {
		case 1:
			// don't jump, reset to location 1
			this.transform.position = new Vector3(jumpPoint1.transform.position.x, jumpPoint1.transform.position.y, this.transform.position.z);
			isJumping = false;
			break;
		case 2:
			JumpTargetLocation = jumpPoint2.transform.position;
			//this.transform.position = new Vector3(jumpPoint2.transform.position.x, this.transform.position.y, this.transform.position.z);
			break;
		case 3:
			JumpTargetLocation = jumpPoint3.transform.position;
			//this.transform.position = new Vector3(jumpPoint3.transform.position.x, this.transform.position.y, this.transform.position.z);
			break;
		case 4:
			JumpTargetLocation = jumpPoint4.transform.position;
			//this.transform.position = new Vector3(jumpPoint4.transform.position.x, this.transform.position.y, this.transform.position.z);
			break;
		case 5:
			JumpTargetLocation = jumpPoint5.transform.position;
			//this.transform.position = new Vector3(jumpPoint5.transform.position.x, this.transform.position.y, this.transform.position.z);
			break;
		case 6:
			JumpTargetLocation = jumpPoint6.transform.position;
			//this.transform.position = new Vector3(jumpPoint6.transform.position.x, this.transform.position.y, this.transform.position.z);
			break;
		default:
			break;
		}
		initialJumpHeight = JumpTargetLocation.y;
		JumpMidPointLocation =  JumpTargetLocation.x + ((this.transform.position.x - JumpTargetLocation.x) / 2);
		if (currentJumpPointNumber % 2 == 0) {
			JumpMidPointLocation += 0.5f;
		} else {
			JumpMidPointLocation -= 0.5f;
		}

	}
}
