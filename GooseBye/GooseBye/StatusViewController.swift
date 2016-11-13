//
//  StatusViewController.swift
//  GooseBye
//
//  Created by Kishan Patel on 10/25/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit

class StatusViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        circularBatteryView.angle = 0.0
        circularBatteryView.animate(toAngle: 180.0, duration: 1, completion: nil)
        batteryPercentage.text = "50%"
        
        // Fetch Weather Data
        dataManager.weatherDataForLocation(latitude: Defaults.Latitude, longitude: Defaults.Longitude) { (response, error) in
            print(response)
        }
    }
    
    private let dataManager = DataManager(baseURL: API.authenticatedBaseURL)
    
    override func viewDidAppear(_ animated: Bool) {
        print("reached Home View")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBOutlet weak var batteryPercentage: UILabel!
    
    @IBOutlet weak var circularBatteryView: CircularProgress!
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
