//
//  WeatherData.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/12/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import Foundation

struct WeatherData {
    
    public let lat: Double
    public let long: Double
    
    public let time: Date
    public let windSpeed: Int
    public let temperature: Double
    public let precipitation: Double

    
    
    public init(lat: Double, long: Double, time: Date, windSpeed: Int, temperature: Double, precipitation: Double) {
        self.lat = lat
        self.long = long
        self.time = time
        self.windSpeed = windSpeed
        self.temperature = temperature
        self.precipitation = precipitation
    }
}
