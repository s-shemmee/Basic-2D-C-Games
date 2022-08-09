using UnityEngine;
using System.Collections;

public class CarDriveLeftSideScript : MonoBehaviour {

	private GameObject startingPoint;
	private GameObject endingPoint;
	
	public float speed = 23.0f;

	IronManBehaviorScript behaviorScript;
	
	// Use this for initialization
	void Start () {
		startingPoint = GameObject.Find ("starting-point");
		endingPoint = GameObject.Find ("ending-point");

		GameObject player = GameObject.FindGameObjectWithTag ("Player");
		behaviorScript = player.GetComponent<IronManBehaviorScript> ();
		
	}
	
	// Update is called once per frame
	void Update () {
		if (behaviorScript.gameOver == true) {
			speed = 0;
		}
		this.transform.position = new Vector3 (this.transform.position.x, this.transform.position.y, this.transform.position.z - speed * Time.deltaTime);
		if (this.transform.position.z < startingPoint.transform.position.z) {
			this.transform.position = new Vector3 (this.transform.position.x, this.transform.position.y, endingPoint.transform.position.z);
		}
		
	}
}
