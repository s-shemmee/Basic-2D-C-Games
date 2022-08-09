using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceScript : MonoBehaviour {

	public GameObject object1;
	public GameObject object2;

	void Start () {
		Vector2 object1Coordinates = object1.transform.position;
		Vector2 object2Coordinates = object2.transform.position;
		float distance = Vector2.Distance (object1Coordinates, object2Coordinates);

		Debug.Log ("the distance between the 2 objects is " + distance.ToString ());
		
	}

}
