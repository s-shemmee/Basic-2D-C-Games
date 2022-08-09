using UnityEngine;
using System.Collections;

public class SpawnEnemyScript : MonoBehaviour {

	public GameObject objectToSpawn;
	public float timeToWaitBetweenSpawns = 2.0f;
	private float timer = 0;

	IronManBehaviorScript behaviorScript;

	// Use this for initialization
	void Start () {
		timer = 0;
		GameObject player = GameObject.FindGameObjectWithTag ("Player");
		behaviorScript = player.GetComponent<IronManBehaviorScript> ();
	
	}
	
	// Update is called once per frame
	void Update () {
		if (behaviorScript.gameOver == true)
			return;
		
		timer += Time.deltaTime;
		if (timer > timeToWaitBetweenSpawns) {
			// todo: spawn the objectToSpawn
			// we need to reset the timer
			Instantiate(objectToSpawn, transform.position, transform.rotation);
			timer = 0;
		}
	
	}
}
