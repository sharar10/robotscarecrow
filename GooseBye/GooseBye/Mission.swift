//
//  Mission.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/11/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit
import MapKit

class Mission: NSObject, NSCoding {
    
    var name: String?
    var sensitivity: String?
    var rect: CGRect?
    
    var latitude: Double?
    var longitude: Double?
    
    var deltaLatitude: Double?
    var deltaLongitude: Double?
    
    static let DocumentsDirectory = FileManager().urls(for: .documentDirectory, in: .userDomainMask).first!
    static let ArchiveURL = DocumentsDirectory.appendingPathComponent("missions")
    
    struct PropertyKey {
        static let nameKey = "name"
        static let sensitivityKey = "sensitivity"
        static let rectKey = "rect"
        static let latitudeKey = "latitude"
        static let longitudeKey = "longitude"
        static let deltaLatitudeKey = "deltaLatitude"
        static let deltaLongitudeKey = "deltaLongitude"
    }
    
    init?(name: String?, sensitivity: String?, rect: CGRect?, latitude: Double?, longitude: Double?, deltaLatitude: Double?, deltaLongitude: Double?) {
        self.name = name
        self.sensitivity = sensitivity
        self.rect = rect
        self.latitude = latitude
        self.longitude = longitude
        self.deltaLatitude = deltaLatitude
        self.deltaLongitude = deltaLongitude
        
        super.init()
        
//        if (name.isEmpty) || (sensitivity.isEmpty) {
//            return nil
//        }
    }
    
    // MARK: NSCoding
    func encode(with aCoder: NSCoder) {
        aCoder.encode(name, forKey: PropertyKey.nameKey)
        aCoder.encode(sensitivity, forKey: PropertyKey.sensitivityKey)
        aCoder.encode(rect, forKey: PropertyKey.rectKey)
        aCoder.encode(latitude, forKey: PropertyKey.latitudeKey)
        aCoder.encode(longitude, forKey: PropertyKey.longitudeKey)
        aCoder.encode(deltaLatitude, forKey: PropertyKey.deltaLatitudeKey)
        aCoder.encode(deltaLongitude, forKey: PropertyKey.deltaLongitudeKey)

    }
    
    required convenience init?(coder aDecoder: NSCoder) {
        let name = aDecoder.decodeObject(forKey: PropertyKey.nameKey) as? String
        let sensitivity = aDecoder.decodeObject(forKey: PropertyKey.sensitivityKey) as? String
        let rect = aDecoder.decodeObject(forKey: PropertyKey.rectKey) as? CGRect
        let latitude = aDecoder.decodeObject(forKey: PropertyKey.latitudeKey) as? Double
        let longitude = aDecoder.decodeObject(forKey: PropertyKey.latitudeKey) as? Double
        let deltaLatitude = aDecoder.decodeObject(forKey: PropertyKey.deltaLatitudeKey) as? Double
        let deltaLongitude = aDecoder.decodeObject(forKey: PropertyKey.deltaLongitudeKey) as? Double

        self.init(name: name, sensitivity: sensitivity, rect: rect, latitude: latitude, longitude: longitude, deltaLatitude: deltaLatitude, deltaLongitude: deltaLongitude)
    }
}


