//
//  WeatherData.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/12/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import Foundation
import UIKit

public struct WeatherData {
    
    public var lat: Double?
    public var long: Double?
    public var time: Date?
    public var windSpeed: Int?
    public var temperature: Double?
    public var precipitationProbability: Double?
    
    public init() {
        
    }
}

//extension WeatherData: JSONDecodable {
//    public init(decoder: JSONDecoder) throws {
//        self.lat = try decoder.decode(key: "latitude")
//        self.long = try decoder.decode(key: "longitude")
//        self.windSpeed = try decoder.decode(key: "windSpeed")
//        self.temperature = try decoder.decode(key: "temperature")
//        self.precipitation = try decoder.decode(key: "precipIntensity")
//        
//        let time: Double = try decoder.decode(key: "time")
//        self.time = Date(timeIntervalSince1970: time)
//    
//    }
//}
