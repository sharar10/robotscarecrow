//
//  NewMissionViewController.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/12/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class NewMissionViewController: UIViewController, UITextFieldDelegate, CLLocationManagerDelegate, MKMapViewDelegate {
    
    // MARK: - Variables
    
    var mission: Mission?
    var locationManager: CLLocationManager!
    var myLocation: CLLocationCoordinate2D?
    @IBOutlet weak var mapView: MKMapView!
    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var sensitivityTextField: UITextField!
    @IBOutlet weak var saveButton: UIBarButtonItem!
    var region: MKCoordinateRegion?
    @IBOutlet weak var rect: UIView!
    
    var inStream: InputStream?
    var outStream: OutputStream?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        //mapView.addSubview(rect)
        //self.mapView.bringSubview(toFront: self.rect)
        
        nameTextField.delegate = self
        sensitivityTextField.delegate = self
        
        if let mission = mission {
            navigationItem.title = mission.name
            nameTextField.text = mission.name
            sensitivityTextField.text = mission.sensitivity
            let center = CLLocationCoordinate2D(latitude: mission.latitude!, longitude: mission.longitude!)
            let span = MKCoordinateSpan(latitudeDelta: mission.deltaLatitude!, longitudeDelta: mission.deltaLongitude!)
            self.region = MKCoordinateRegion(center: center, span: span)
            self.rect.frame = mission.rect!
            //set map to show region
        }
        checkValidMissionName()
        
        locationManagerSetup()
        getLocation()
        mapSetup()
        setConstraints()
    }
    
    @IBAction func sendMissionPress() {
        print("lets send that mission")
        
        let jsonObject: [String: AnyObject] = [
            "name": self.mission?.name as AnyObject,
            "sensitivity": self.mission?.sensitivity as AnyObject,
            "latitude": self.mission?.latitude as AnyObject,
            "longitude": self.mission?.longitude as AnyObject
        ]
        
        let valid = JSONSerialization.isValidJSONObject(jsonObject) // true

        print(valid)
        
        let data : Data = "hello. This is IPHONE ".data(using: String.Encoding.utf8)!
        //outStream?.write(UnsafePointer<UInt8>(data.bytes), maxLength: data.length)
        let bytesWritten = data.withUnsafeBytes { outStream?.write($0, maxLength: data.count) }
        print(bytesWritten ?? "nil")
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(true)
        mapView.showsUserLocation = true
    }
    
    override func viewDidAppear(_ animated: Bool) {
        
    }
    
    @IBAction func cancelPress(_ sender: UIBarButtonItem) {
        let isPresentingInAddMissionMode = presentingViewController is UINavigationController
        if isPresentingInAddMissionMode {
            dismiss(animated: true, completion: nil)
        }
        else {
            _ = navigationController?.popViewController(animated: true)
            dismiss(animated: true, completion: nil)
        }
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        saveButton.isEnabled = false
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        checkValidMissionName()
        let text = nameTextField.text ?? ""
        if !text.isEmpty {
            navigationItem.title = nameTextField.text
        }
        else {
            navigationItem.title = "New Mission"
        }
    }
    
    func checkValidMissionName() {
        let text = nameTextField.text ?? ""
        saveButton.isEnabled = !text.isEmpty
    }
    
    // MARK: - Field Area
    
    @IBAction func scaleRect(_ sender: UIPinchGestureRecognizer) {
        self.rect.transform = CGAffineTransform(scaleX: sender.scale, y: sender.scale)
        //sender.scale = 1
    }
    
    func setConstraints() {
        //self.rect.translatesAutoresizingMaskIntoConstraints = false
        let rectMinHeightConstraint = NSLayoutConstraint(item: self.rect, attribute: NSLayoutAttribute.height, relatedBy: NSLayoutRelation.greaterThanOrEqual, toItem: nil, attribute: NSLayoutAttribute.notAnAttribute, multiplier: 1, constant: 75)
        let rectMaxHeightConstraint = NSLayoutConstraint(item: self.rect, attribute: NSLayoutAttribute.height, relatedBy: NSLayoutRelation.lessThanOrEqual, toItem: nil, attribute: NSLayoutAttribute.notAnAttribute, multiplier: 1, constant: 300)
        let rectMinWidthConstraint = NSLayoutConstraint(item: self.rect, attribute: NSLayoutAttribute.width, relatedBy: NSLayoutRelation.greaterThanOrEqual, toItem: nil, attribute: NSLayoutAttribute.notAnAttribute, multiplier: 1, constant: 75)
        let rectMaxWidthConstraint = NSLayoutConstraint(item: self.rect, attribute: NSLayoutAttribute.width, relatedBy: NSLayoutRelation.lessThanOrEqual, toItem: nil, attribute: NSLayoutAttribute.notAnAttribute, multiplier: 1, constant: 300)
        self.rect.addConstraints([rectMinHeightConstraint, rectMaxHeightConstraint, rectMinWidthConstraint, rectMaxWidthConstraint])
    }
    
    // MARK: - Map
    
    func locationManagerSetup() {
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.requestWhenInUseAuthorization()
    }
    
    func getLocation() {
        if CLLocationManager.locationServicesEnabled() {
            locationManager.requestLocation()
        }
    }
    
    func mapSetup() {
        if let coor = mapView.userLocation.location?.coordinate{
            mapView.setCenter(coor, animated: true)
        }
        mapView.delegate = self
        mapView.mapType = .standard
        mapView.isZoomEnabled = true
        mapView.isScrollEnabled = true
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let locValue:CLLocationCoordinate2D = locationManager.location!.coordinate
        
        centerMap(center: locValue)
    }
    
    func centerMap(center: CLLocationCoordinate2D) {
        self.saveCurrentLocation(center: center)
        
        let spanX = 0.007
        let spanY = 0.007
        
        let newRegion = MKCoordinateRegion(center:center , span: MKCoordinateSpanMake(spanX, spanY))
        if (self.region != nil) {
            mapView.setRegion(region!, animated: true)
        }
        else {
            mapView.setRegion(newRegion, animated: true)
        }
    }
    
    func saveCurrentLocation(center: CLLocationCoordinate2D){
        myLocation = center
    }
    
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("Failed to find user's location: \(error.localizedDescription)")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Navigation

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if saveButton === sender as AnyObject {
            let name = nameTextField.text ?? ""
            let sensitivity = sensitivityTextField.text
            let missionRect = self.rect.frame
            
            let missionRegion = mapView.convert(self.mapView.frame, toRegionFrom: self.view)
            let latitude = missionRegion.center.latitude
            let longitude = missionRegion.center.longitude
            let deltaLatitude = missionRegion.span.latitudeDelta
            let deltaLongitude = missionRegion.span.longitudeDelta
            
            let mapAngle = self.mapView.camera.heading
            
            print("angle: \(mapAngle)")
            print("name: \(name)")
            print("sensitivity: \(sensitivity)")
            print("region: \(mapView.convert(self.rect.frame, toRegionFrom: self.view))")
            
            mission = Mission(name: name, sensitivity: sensitivity, rect: missionRect, latitude: latitude, longitude: longitude, deltaLatitude: deltaLatitude, deltaLongitude: deltaLongitude)
        }
    }
}
