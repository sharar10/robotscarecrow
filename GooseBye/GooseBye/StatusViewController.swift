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
        loadWeather();
        
        let tapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(disablePress(img:)))
        disableImage.addGestureRecognizer(tapGestureRecognizer)
    }
    
    @IBOutlet weak var disableImage: UIImageView!
    
    @IBOutlet weak var disableLabel: UILabel!
    
    
    func disablePress(img: AnyObject) {
        print("disable!")
    }
    
    func loadWeather() {
        dataManager.weatherDataForLocation(latitude: 42.36, longitude: -71.06)
        {
            (response, error) in
            if response != nil {
                let currentWeatherJSON: NSDictionary = (response?.object(forKey: "currently") ?? "N/A") as! NSDictionary
                self.currentWeatherData.temperature = currentWeatherJSON.object(forKey: "temperature") as! Double?
                var timeSince1970 = currentWeatherJSON.object(forKey: "time") as! Double
                timeSince1970 -= 18000 //account for timezone difference
                self.currentWeatherData.time = Date(timeIntervalSince1970: timeSince1970) as Date?
                self.currentWeatherData.windSpeed = currentWeatherJSON.object(forKey: "windSpeed") as! Int?
                self.currentWeatherData.precipitationProbability = currentWeatherJSON.object(forKey: "precipProbability") as! Double?
                //print(response)
                let iconDesc: String = currentWeatherJSON.object(forKey: "icon") as! String
                let iconImage: UIImage? = UIImage(named: iconDesc)
                DispatchQueue.main.async(execute: {
                    self.currentTemp.text = "\(self.currentWeatherData.temperature!) ℉"
                    self.currentWeatherIcon.image = iconImage ?? #imageLiteral(resourceName: "default")
                })
                print(" ")
                print(self.currentWeatherData)
                print(" ")
            }
            else {
                print("no data")
            }
            
        }
        
    }
    
    private let dataManager = DataManager(baseURL: weatherAPI.authenticatedBaseURL)
    private var currentWeatherData = WeatherData()
    
    @IBOutlet weak var currentWeatherIcon: UIImageView!
    
    @IBOutlet weak var currentTemp: UILabel!
    
    override func viewDidAppear(_ animated: Bool) {
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
