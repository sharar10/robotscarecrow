//
//  Mission.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/11/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit

class Mission: NSObject, NSCoding {
    
    var name: String?
    var sensitivity: String?
    
    static let DocumentsDirectory = FileManager().urls(for: .documentDirectory, in: .userDomainMask).first!
    static let ArchiveURL = DocumentsDirectory.appendingPathComponent("missions")
    
    struct PropertyKey {
        static let nameKey = "name"
        static let sensitivityKey = "sensitivity"
    }
    
    init?(name: String?, sensitivity: String?) {
        self.name = name
        self.sensitivity = sensitivity
        
        super.init()
        
//        if (name.isEmpty) || (sensitivity.isEmpty) {
//            return nil
//        }
    }
    
    // MARK: NSCoding
    func encode(with aCoder: NSCoder) {
        aCoder.encode(name, forKey: PropertyKey.nameKey)
        aCoder.encode(sensitivity, forKey: PropertyKey.sensitivityKey)
    }
    
    required convenience init?(coder aDecoder: NSCoder) {
        let name = aDecoder.decodeObject(forKey: PropertyKey.nameKey) as? String
        let sensitivity = aDecoder.decodeObject(forKey: PropertyKey.sensitivityKey) as? String
        self.init(name: name, sensitivity: sensitivity)

    }
}


